/*
** xfunc.c for lol in /u/all/nguyen_7/public/alum-1
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sat Feb 13 16:41:13 2010 damien locque
** Last update Sat Feb 13 17:34:34 2010 damien locque
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "my.h"

SDL_Surface	*xSDL_LoadBMP(const char *file)
{
  if (SDL_LoadBMP(file) == NULL)
    {
      my_puterror("Load Failed");
      exit(EXIT_FAILURE);
    }
  return (SDL_LoadBMP(file));
}

void		xSDL_WaitEvent(SDL_Event *event)
{
  if (SDL_WaitEvent(event) == 0)
    {
      my_puterror("Event Failed");
      exit(EXIT_FAILURE);
    }
}

void		xSDL_Flip(SDL_Surface *screen)
{
  if (SDL_Flip(screen) == -1)
    {
      my_puterror("Flip Failed");
      exit(EXIT_FAILURE);
    }
  else
    SDL_Flip(screen);
}

void		xSDL_FillRect(SDL_Surface *dst,
			      SDL_Rect *dstrect, Uint32 color)
{
  if (SDL_FillRect(dst, dstrect, color) == -1)
    {
      my_puterror("Fill Rect Failed");
      exit(EXIT_FAILURE);
    }
  else
    SDL_FillRect(dst, dstrect, color);
}


void		xSDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect,
				 SDL_Surface *dst, SDL_Rect *dstrect)
{
  if (SDL_BlitSurface(src, srcrect, dst, dstrect) == -1)
    {
      my_puterror("Blit failed");
      exit(EXIT_FAILURE);
    }
  else
    SDL_BlitSurface(src, srcrect, dst, dstrect);
}
