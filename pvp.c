/*
** pvp.c for pvp in /u/all/nguyen_7/cu/public/alum-1
**
** Made by julien nguyen-duy
** Login   <nguyen_7@epitech.net>
**
** Started on  Fri Feb 12 12:59:59 2010 julien nguyen-duy
** Last update Sat Feb 13 17:41:44 2010 damien locque
*/

#include "my.h"
#include <SDL/SDL.h>
#include <unistd.h>

static int	who_play = 0;
static int	win = 0;

t_match		*check_space_pvp(t_match *match, int flag)
{
  int		check;

  check = 0;
  if (check_list(match) == 1)
    {
      flag = 1;
      return (match);
    }
  check = init_check(match);
  if (is_ok(match, check) == 1)
    {
      flag = 1;
      return (match);
    }
  flag = burn_select(&match, flag);
  if (flag != 0)
    {
      is_finished(match);
      if (who_play == 0)
	who_play = 42;
      else
	who_play = 0;
    }
  return (match);
}

int		aff_win_pvp(t_var var, int in_prog, int who_play)
{
  SDL_Event	event;
  SDL_Rect	pos;

  pos.x = 0;
  pos.y = 0;
  if (who_play != 0)
    xSDL_BlitSurface(var.winp2, NULL, var.screen, &pos);
  else
    xSDL_BlitSurface(var.winp1, NULL, var.screen, &pos);
  xSDL_Flip(var.screen);
  while (in_prog == 1)
    {
      xSDL_WaitEvent(&event);
      if (event.type == SDL_KEYDOWN)
	if (event.key.keysym.sym == SDLK_ESCAPE)
	  in_prog = 42;
    }
  return (42);
}

int		catch_event_pvp(t_match **match, t_var *var,
			    int in_prog, SDL_Event event)
{
  int		flag;

  flag = 0;
  xSDL_WaitEvent(&event);
  aff_p1_p2(who_play, var);
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
	check_space_pvp((*match), flag);
    }
  aff_match(var, (*match));
  if (win != 0)
    in_prog = aff_win_pvp((*var), in_prog, who_play);
  xSDL_Flip(var->screen);
  is_finished_pvp(*match);
  return (in_prog);
}

void		wait_event_pvp(t_var var)
{
  SDL_Event	event;
  t_match	*match;
  int		in_prog;

  match = NULL;
  in_prog = 1;
  match = init_match(match);
  SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
  aff_bwall(&var);
  aff_match(&var, match);
  xSDL_Flip(var.screen);
  while (in_prog == 1)
    in_prog = catch_event_pvp(&match, &var, in_prog, event);
  aff_match(&var, match);
  free_all(match, &var);
  SDL_Quit();
  exit(EXIT_SUCCESS);
}

int		is_finished_pvp(t_match *match)
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
