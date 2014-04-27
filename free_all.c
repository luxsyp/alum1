/*
** wait_event.c for lol in /u/all/nguyen_7/public/alum-1
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Fri Feb 12 10:54:15 2010 damien locque
** Last update Sat Feb 13 16:23:48 2010 damien locque
*/

#include "my.h"
#include <unistd.h>
#include <SDL/SDL.h>

void		free_all(t_match *match ,t_var *var)
{
  t_match	*temp;
  t_match	*tmpnxt;

  SDL_FreeSurface(var->winner);
  SDL_FreeSurface(var->loser);
  SDL_FreeSurface(var->alum);
  SDL_FreeSurface(var->clique);
  SDL_FreeSurface(var->burn);
  SDL_FreeSurface(var->player1);
  SDL_FreeSurface(var->cpu);
  SDL_FreeSurface(var->bwall);
  SDL_FreeSurface(var->winp1);
  SDL_FreeSurface(var->winp2);
  SDL_FreeSurface(var->player1pvp);
  SDL_FreeSurface(var->player2pvp);
  temp = match;
  while (temp != NULL)
    {
      tmpnxt = temp->next;
      free(temp);
      temp = tmpnxt;
    }
  free(temp);
}
