/*
** static.c for static in /u/all/nguyen_7/cu/rendu/dirtest/alum_++/bin
**
** Made by julien nguyen-duy
** Login   <nguyen_7@epitech.net>
**
** Started on  Thu Feb 11 17:50:17 2010 julien nguyen-duy
** Last update Sat Feb 13 17:42:28 2010 damien locque
*/

#include "my.h"
#include <SDL/SDL.h>
#include <unistd.h>

static int	who_play = 0;
static int	win = 0;

t_match		*cpu_play(t_match *match, t_var *var)
{
  int		nb_line;
  int		the_play_line;
  int		match_to_play;

  aff_cpu(&var);
  xSDL_Flip(var->screen);
  sleep(1);
  nb_line = nbr_of_line(match);
  if (nb_line == 1)
    match = play_last_line(match);
  else
    {
      the_play_line = line_to_play(match, nb_line);
      match_to_play = rand_match(match, the_play_line);
      match = cpu_playing(match, the_play_line, match_to_play);
    }
  who_play = 0;
  is_finished(match);
  return (match);
}

t_match		*check_space(t_match *match)
{
  int		check;
  int		flag;

  check = 0;
  flag = 0;
  if (check_list(match) == 1)
    return (match);
  check = init_check(match);
  if (is_ok(match, check) == 1)
    return (match);
  flag = burn_select(&match, flag);
  if (flag != 0)
    {
      is_finished(match);
      who_play = 42;
    }
  return (match);
}

int		catch_event(t_match **match, t_var *var,
			    int in_prog, SDL_Event event)
{
  if (who_play == 0)
    {
      xSDL_WaitEvent(&event);
      aff_player(&var);
      if (event.type == SDL_QUIT)
	in_prog = 42;
      if (event.type == SDL_MOUSEBUTTONDOWN)
	if (event.button.button == SDL_BUTTON_LEFT)
	  (*match) = catch_left_button(&event, (*match));
      if (event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_ESCAPE)
	    in_prog = 42;
	  else if (event.key.keysym.sym == SDLK_SPACE)
	    check_space((*match));
	}
      aff_match(var, (*match));
      if (win != 0)
	in_prog = aff_win((*var), in_prog, who_play);
      xSDL_Flip(var->screen);
    }
  else
    (*match) = cpu_play(*match, var);
  return (in_prog);
}

void		wait_event(t_var var)
{
  SDL_Event	event;
  t_match	*match;
  int		in_prog;

  match = NULL;
  in_prog = 1;
  match = init_match(match);
  SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
  aff_match(&var, match);
  xSDL_Flip(var.screen);
  while (in_prog == 1)
    in_prog = catch_event(&match, &var, in_prog, event);
  aff_match(&var, match);
  free_all(match, &var);
  SDL_Quit();
}

int		is_finished(t_match *match)
{
  t_match	*temp;

  temp = match;
  while (temp->next != NULL)
    {
      if (temp->burn == 0)
	return (0);
      temp = temp->next;
    }
  if (temp->burn == 0)
    return (0);
  win = 42;
  return (0);
}
