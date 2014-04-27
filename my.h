/*
** my.h for my_h_alum1 in /u/all/nguyen_7/cu/rendu/dirtest/alum/SDL/bin
**
** Made by julien nguyen-duy
** Login   <nguyen_7@epitech.net>
**
** Started on  Wed Feb 10 14:21:13 2010 julien nguyen-duy
** Last update Sat Feb 13 17:35:16 2010 damien locque
*/

#ifndef         __MY_H__
# define	__MY_H__

#include	<SDL/SDL.h>
#include	<unistd.h>
#include	<stdlib.h>

typedef struct	s_list
{
  int		burn;
  int		line;
  int		select;
  SDL_Rect	pos;
  struct s_list	*next;
}		t_match;

typedef struct	s_var
{
  SDL_Rect	pos_wall;
  SDL_Rect	pos_p1;
  SDL_Rect	pos_cpu;
  SDL_Rect	pos_pai;
  SDL_Rect	pos_pvp;
  SDL_Rect	pos_bwall;
  SDL_Surface	*loser;
  SDL_Surface	*winner;
  SDL_Surface	*winp1;
  SDL_Surface	*winp2;
  SDL_Surface	*player1pvp;
  SDL_Surface	*player2pvp;
  SDL_Surface	*alum;
  SDL_Surface	*burn;
  SDL_Surface	*wall;
  SDL_Surface	*bwall;
  SDL_Surface	*play_cpu;
  SDL_Surface	*play_play;
  SDL_Surface	*cpu;
  SDL_Surface	*screen;
  SDL_Surface	*clique;
  SDL_Surface	*player1;
  SDL_Surface	*p1_win;
  SDL_Surface	*cpu_win;
}		t_var;

/* free_all.c */
void		free_all(t_match *match ,t_var *var);

/* match_func.c */
t_match		*info_to_match(t_match *list, int line, int x, int y);
t_match		*init_match(t_match *match);
void		select_match(t_match **temp);
t_match		*catch_left_button(SDL_Event *event, t_match *match);

/* ai.c */
t_match		*play_last_line(t_match *match);
int		search_line(t_match *match, int the_line);
int		line_to_play(t_match *match, int nb_line);
int		rand_match(t_match *match, int the_line);
t_match		*cpu_playing(t_match *match, int line, int nb_match);

/* ai2.c */
int		nbr_of_line(t_match *match);
int		two_last_line(t_match *match, int the_line);

/* check_space.c */
int		init_check(t_match *match);
int		check_list(t_match *match);
int		is_ok(t_match *match, int check);
int		burn_select(t_match **match, int flag);

/* static.c */
t_match		*cpu_play(t_match *match, t_var *var);
t_match		*check_space(t_match *match);
int		catch_event(t_match **match, t_var *var,
			    int in_prog, SDL_Event event);
void		wait_event(t_var var);
int		is_finished(t_match *match);

/* init.c */
void		init_var(t_var *var);
void		init_menu(t_var **var);

/* try_win.c */
int		match_count(t_match *match);
t_match		*play_2match(t_match *match, int nb_match);

/* aff.c */
int		aff_win(t_var var, int in_prog, int who_play);
void		aff_match(t_var *var, t_match *match);
void		aff_player(t_var **var);
void		aff_cpu(t_var **var);
void		aff_bwall(t_var *var);

/* affpvp.c */
void		aff_player1_pvp(t_var **var);
void		aff_player2_pvp(t_var **var);
void		aff_p1_p2(int who_play, t_var *var);

/* pvp.c */
t_match		*check_space_pvp(t_match *match, int flag);
int		aff_win_pvp(t_var var, int in_prog, int who_play);
int		catch_event_pvp(t_match **match, t_var *var,
				int in_prog, SDL_Event event);
void		wait_event_pvp(t_var var);
int		is_finished_pvp(t_match *match);

/* main.c */
int		where_left_button(t_var *var, SDL_Event *event);
void		aff_menu(t_var *var);

/* xfunc.c */
void		*xmalloc(size_t size);
void		my_puterror(char *str);
int		xwrite(int d, void *buf, int nbytes);

/* xfuncSDL.c */
SDL_Surface	*xSDL_LoadBMP(const char *file);
void		xSDL_WaitEvent(SDL_Event *event);
void		xSDL_Flip(SDL_Surface *screen);
void		xSDL_FillRect(SDL_Surface *dst,
			      SDL_Rect *dstrect, Uint32 color);
void		xSDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect,
				 SDL_Surface *dst, SDL_Rect *dstrect);

#endif		/* __MY_H__ */
