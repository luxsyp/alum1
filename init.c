/*
** init.c for init_alum in /u/all/nguyen_7/cu/rendu/dirtest/alum_++/bin
**
** Made by julien nguyen-duy
** Login   <nguyen_7@epitech.net>
**
** Started on  Thu Feb 11 18:13:44 2010 julien nguyen-duy
** Last update Mon Mar  8 14:36:40 2010 damien locque
*/

#include "my.h"
#include <unistd.h>
#include <SDL/SDL.h>

void		init_menu(t_var **var)
{
  (*var)->pos_wall.x = 0;
  (*var)->pos_wall.y = 0;
  (*var)->pos_pai.x = 150;
  (*var)->pos_pai.y = 100;
  (*var)->pos_pvp.x = 150;
  (*var)->pos_pvp.y = 350;
  xSDL_BlitSurface((*var)->wall, NULL, (*var)->screen, &((*var)->pos_wall));
  if (SDL_SetColorKey((*var)->play_play, SDL_SRCCOLORKEY,
		      SDL_MapRGB((*var)->play_play->format, 0, 0, 255)) == -1)
    {
      my_puterror("Sdl Set Color Key Failed");
      exit(EXIT_FAILURE);
    }
  xSDL_BlitSurface((*var)->play_play, NULL, (*var)->screen, &((*var)->pos_pai));
  if (SDL_SetColorKey((*var)->play_cpu, SDL_SRCCOLORKEY,
		      SDL_MapRGB((*var)->play_cpu->format, 0, 0, 255)) == -1)
    {
      my_puterror("Sdl Set Color Key Failed");
      exit(EXIT_FAILURE);
    }
    xSDL_BlitSurface((*var)->play_cpu, NULL,
		     (*var)->screen, &((*var)->pos_pvp));
  xSDL_Flip((*var)->screen);
}

void		init_var(t_var *var)
{
  var->wall = xSDL_LoadBMP("./img/menu.bmp");
  var->play_play = xSDL_LoadBMP("./img/pvp.bmp");
  var->play_cpu = xSDL_LoadBMP("./img/p_vs_ai.bmp");
  var->winner = xSDL_LoadBMP("./img/winner.bmp");
  var->loser = xSDL_LoadBMP("./img/lose.bmp");
  var->alum = xSDL_LoadBMP("./img/alum.bmp");
  var->clique = xSDL_LoadBMP("./img/is_burning.bmp");
  var->burn = xSDL_LoadBMP("./img/burn.bmp");
  var->player1 = xSDL_LoadBMP("./img/player_1.bmp");
  var->cpu = xSDL_LoadBMP("./img/ia_img.bmp");
  var->bwall = xSDL_LoadBMP("./img/black_wall.bmp");
  var->winp1 = xSDL_LoadBMP("./img/winner_pvp1.bmp");
  var->winp2 = xSDL_LoadBMP("./img/winner_pvp2.bmp");
  var->player1pvp = xSDL_LoadBMP("./img/player1pvp.bmp");
  var->player2pvp = xSDL_LoadBMP("./img/player2pvp.bmp");
  var->pos_p1.x = 50;
  var->pos_p1.y = 50;
  var->pos_cpu.x = 50;
  var->pos_cpu.y = 50;
  aff_menu(var);
  xSDL_FillRect(var->screen, NULL, SDL_MapRGB(var->screen->format, 0, 0, 0));
}
