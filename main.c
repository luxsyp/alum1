/*
** test.c for lol in /u/all/locque_d/cu/rendu/c/alum1/usr/bin
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Mon Feb  8 11:16:33 2010 damien locque
** Last update Sat Feb 13 17:40:33 2010 damien locque
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <SDL/SDL.h>
#include "my.h"

const int	WIDTH = 800;
const int	HEIGHT = 600;

int		where_left_button(t_var *var, SDL_Event *event)
{
  if ((*event).button.x >= var->pos_pai.x
      && (*event).button.x <= (var->pos_pai.x + 500)
      && (*event).button.y >= var->pos_pai.y
      && ((*event).button.y <= var->pos_pai.y + 200))
    return (5);
  if ((*event).button.x >= var->pos_pvp.x
      && (*event).button.x <= (var->pos_pvp.x + 500)
      && (*event).button.y >= var->pos_pvp.y
      && ((*event).button.y <= var->pos_pvp.y + 200))
    return (42);
  return (1);
}

void		aff_menu(t_var *var)
{
  SDL_Event	event;
  int		in_prog;

  in_prog = 1;
  init_menu(&var);
  SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
  while (in_prog == 1)
    {
      xSDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	in_prog = 21;
      if (event.type == SDL_KEYDOWN)
	if (event.key.keysym.sym == SDLK_ESCAPE)
	  in_prog = 21;
      if (event.type == SDL_MOUSEBUTTONDOWN)
	if (event.button.button == SDL_BUTTON_LEFT)
	  in_prog = where_left_button(var, &event);
    }
  SDL_FreeSurface(var->wall);
  SDL_FreeSurface(var->play_cpu);
  SDL_FreeSurface(var->play_play);
  if (in_prog == 21)
    exit(EXIT_SUCCESS);
  if (in_prog == 5)
    wait_event_pvp(*var);
}

int		main(void)
{
  t_var		var;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      my_puterror("Init failed\n");
      exit(EXIT_FAILURE);
    }
  var.screen = NULL;
  var.screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32,
				SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (var.screen == NULL)
    {
      my_puterror("Set Video Mode failed\n");
      exit(EXIT_FAILURE);
    }
  SDL_WM_SetCaption("Alum1", NULL);
  init_var(&var);
  wait_event(var);
  return (EXIT_SUCCESS);
}
