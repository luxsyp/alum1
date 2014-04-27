/*
** aff.c for aff in /u/all/nguyen_7/cu/public/alum-1
**
** Made by julien nguyen-duy
** Login   <nguyen_7@epitech.net>
**
** Started on  Thu Feb 11 19:06:29 2010 julien nguyen-duy
** Last update Sat Feb 13 17:37:36 2010 damien locque
*/

#include <SDL/SDL.h>
#include "my.h"

int		aff_win(t_var var, int in_prog, int who_play)
{
  SDL_Event	event;
  SDL_Rect	pos;

  pos.x = 0;
  pos.y = 0;
  if (who_play != 0)
    xSDL_BlitSurface(var.loser, NULL, var.screen, &pos);
  else
    xSDL_BlitSurface(var.winner, NULL, var.screen, &pos);
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

void		aff_match(t_var *var, t_match *match)
{
  t_match	*temp;

  temp = match;
  while (temp->next != NULL)
    {
      if (temp->burn == 1)
	xSDL_BlitSurface(var->burn, NULL, var->screen, &(temp->pos));
      else if (temp->select == 0)
	xSDL_BlitSurface(var->alum, NULL, var->screen, &(temp->pos));
      else if (temp->select == 1)
	xSDL_BlitSurface(var->clique, NULL, var->screen, &(temp->pos));
      temp = temp->next;
    }
  if (temp->burn == 1)
    xSDL_BlitSurface(var->burn, NULL, var->screen, &(temp->pos));
  else if (temp->select == 0)
    xSDL_BlitSurface(var->alum, NULL, var->screen, &(temp->pos));
  else
    xSDL_BlitSurface(var->clique, NULL, var->screen, &(temp->pos));
  xSDL_Flip(var->screen);
}

void		aff_player(t_var **var)
{
  if (SDL_SetColorKey((*var)->player1, SDL_SRCCOLORKEY,
		      SDL_MapRGB((*var)->player1->format, 0, 0, 255)) == -1)
    {
      my_puterror("Sdl Set Color Key Failed");
      exit(EXIT_FAILURE);
    }
  xSDL_BlitSurface((*var)->player1, NULL, (*var)->screen, &((*var)->pos_p1));
}

void		aff_cpu(t_var **var)
{
  if (SDL_SetColorKey((*var)->cpu, SDL_SRCCOLORKEY,
		      SDL_MapRGB((*var)->cpu->format, 0, 0, 255)) == -1)
    {
      my_puterror("Sdl Set Color Key Failed");
      exit(EXIT_FAILURE);
    }
  xSDL_BlitSurface((*var)->cpu, NULL, (*var)->screen, &((*var)->pos_cpu));
}

void		aff_bwall(t_var *var)
{
  var->pos_bwall.x = 0;
  var->pos_bwall.y = 0;

  xSDL_BlitSurface(var->bwall, NULL, var->screen, &(var->pos_bwall));
}
