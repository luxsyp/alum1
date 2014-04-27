/*
** match_func.c for match_func in /u/all/nguyen_7/cu/rendu/dirtest/alum_++/bin
**
** Made by julien nguyen-duy
** Login   <nguyen_7@epitech.net>
**
** Started on  Thu Feb 11 17:21:40 2010 julien nguyen-duy
** Last update Sat Feb 13 16:46:42 2010 damien locque
*/

#include "my.h"
#include <unistd.h>
#include <SDL/SDL.h>

t_match		*info_to_match(t_match *list, int line, int x, int y)
{
  t_match	*new;
  t_match	*temp;

  new = xmalloc(sizeof(t_match));
  new->burn = 0;
  new->line = line;
  new->select = 0;
  new->pos.x = x;
  new->pos.y = y;
  new->next = NULL;
  if (list == NULL)
    return (new);
  else
    {
      temp = list;
      while (temp->next != NULL)
	temp = temp->next;
      temp->next = new;
      return (list);
    }
}

t_match		*init_match(t_match *match)
{
  match = info_to_match(match, 1, 380, 40);
  match = info_to_match(match, 2, 280, 180);
  match = info_to_match(match, 2, 380, 180);
  match = info_to_match(match, 2, 480, 180);
  match = info_to_match(match, 3, 180, 320);
  match = info_to_match(match, 3, 280, 320);
  match = info_to_match(match, 3, 380, 320);
  match = info_to_match(match, 3, 480, 320);
  match = info_to_match(match, 3, 580, 320);
  match = info_to_match(match, 4, 80, 460);
  match = info_to_match(match, 4, 180, 460);
  match = info_to_match(match, 4, 280, 460);
  match = info_to_match(match, 4, 380, 460);
  match = info_to_match(match, 4, 480, 460);
  match = info_to_match(match, 4, 580, 460);
  match = info_to_match(match, 4, 680, 460);
  return (match);
}

void		select_match(t_match **temp)
{
  if ((*temp)->burn == 0)
    {
      if ((*temp)->select == 1)
	(*temp)->select = 0;
      else
	(*temp)->select = 1;
    }
}

t_match		*catch_left_button(SDL_Event *event, t_match *match)
{
  t_match	*temp;

  temp = match;
  while (temp->next != NULL)
    {
      if ((*event).button.x >= temp->pos.x &&
	  (*event).button.x <= (temp->pos.x + 43) &&
	  (*event).button.y >= temp->pos.y &&
	  ((*event).button.y <= temp->pos.y + 100))
	select_match(&temp);
      temp = temp->next;
    }
  if ((*event).button.x >= temp->pos.x &&
      (*event).button.x <= (temp->pos.x + 43) &&
      (*event).button.y >= temp->pos.y &&
      ((*event).button.y <= temp->pos.y + 100))
    select_match(&temp);
  return (match);
}
