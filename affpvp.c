/*
** affpvp.c for aff pvp in /u/all/nguyen_7/public/alum-1
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sat Feb 13 16:25:43 2010 damien locque
** Last update Sat Feb 13 17:37:46 2010 damien locque
*/

#include <SDL/SDL.h>
#include "my.h"

void		aff_player1_pvp(t_var **var)
{
  xSDL_BlitSurface((*var)->player1pvp, NULL, (*var)->screen, &((*var)->pos_p1));
}

void		aff_player2_pvp(t_var **var)
{
  xSDL_BlitSurface((*var)->player2pvp, NULL, (*var)->screen, &((*var)->pos_cpu));
}

void		aff_p1_p2(int who_play, t_var *var)
{
  if (who_play == 0)
    aff_player1_pvp(&var);
  else
    aff_player2_pvp(&var);
}
