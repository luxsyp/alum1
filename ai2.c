/*
** ai2.c for ai2_alum in /u/all/nguyen_7/cu/rendu/dirtest/alum_++/bin
**
** Made by julien nguyen-duy
** Login   <nguyen_7@epitech.net>
**
** Started on  Thu Feb 11 17:28:38 2010 julien nguyen-duy
** Last update Fri Feb 12 11:24:07 2010 damien locque
*/

#include "my.h"
#include <unistd.h>

int		nbr_of_line(t_match *match)
{
  int		nb_line;
  int		cur_line;
  t_match	*temp;

  nb_line = 0;
  cur_line = 0;
  temp = match;
  while (temp->next != NULL)
    {
      if (temp->burn == 0)
	if (cur_line < temp->line)
	  {
	    cur_line = temp->line;
	    nb_line++;
	  }
      temp = temp->next;
    }
  if (temp->burn == 0)
    if (cur_line < temp->line)
      {
	cur_line = temp->line;
	nb_line++;
      }
  return (nb_line);
}

int		two_last_line(t_match *match, int the_line)
{
  int		nvoid_line;
  t_match	*temp;
  int		check;

  check = 0;
  nvoid_line = 0;
  temp = match;
  while (nvoid_line != the_line && temp->next != NULL)
    {
      if (temp->burn != 1)
	if (check != temp->line)
	  {
	    nvoid_line++;
	    check = temp->line;
	  }
      temp = temp->next;
    }
  if (nvoid_line != the_line)
    if (temp->burn != 1)
      if (check != temp->line)
	{
	  nvoid_line++;
	  check = temp->line;
	}
  return (check);
}
