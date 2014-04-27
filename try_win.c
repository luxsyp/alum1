/*
** try_win.c for try_win in /u/all/nguyen_7/cu/rendu/dirtest/alum_++/bin
**
** Made by julien nguyen-duy
** Login   <nguyen_7@epitech.net>
**
** Started on  Thu Feb 11 18:21:02 2010 julien nguyen-duy
** Last update Sat Feb 13 17:13:28 2010 damien locque
*/

#include <unistd.h>
#include "my.h"

int		match_count(t_match *match)
{
  int		nb_match;
  t_match	*temp;

  temp = match;
  nb_match = 0;
  temp = match;
  while (temp->next != NULL)
    {
      if (temp->burn == 0)
	nb_match++;
      temp = temp->next;
    }
  if (temp->burn == 0)
    nb_match++;
  nb_match--;
  return (nb_match);
}

t_match		*play_2match(t_match *match, int nb_match)
{
  t_match	*temp;

  temp = match;
  while (temp->next != NULL && nb_match != 0)
    {
      if (temp->burn == 0)
	{
	  temp->burn = 1;
	  nb_match--;
	}
      temp = temp->next;
    }
  if (nb_match != 0)
    if (temp->burn == 0)
      {
	temp->burn = 1;
	nb_match--;
      }
  return (match);
}
