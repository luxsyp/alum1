/*
** check_space.c for check space in /u/all/nguyen_7/public/alum-1
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Fri Feb 12 11:02:01 2010 damien locque
** Last update Fri Feb 12 12:12:34 2010 damien locque
*/

#include <SDL/SDL.h>
#include "my.h"

int		check_list(t_match *match)
{
  t_match	*temp;

  temp = match;
  while (temp->next != NULL)
    {
      if (temp->burn == 0)
	if (temp->select == 1)
	  return (0);
      temp = temp->next;
    }
  if (temp->burn == 0)
    if (temp->select == 1)
      return (0);
  return (1);
}

int		init_check(t_match *match)
{
  int		check;
  t_match	*temp;

  check = 0;
  temp = match;
  while (temp->next != NULL)
    {
      if (temp->burn == 0)
	if (temp->select == 1)
	  {
	    check = temp->line;
	    return (check);
	  }
      temp = temp->next;
    }
  if (temp->burn == 0)
    if (temp->select == 1)
      return (temp->line);
  return (0);
}

int		is_ok(t_match *match, int check)
{
  t_match	*temp;

  temp = match;
  while (temp->next != NULL)
    {
      if (temp->burn == 0)
	if (temp->select == 1)
	  if (temp->line != check)
	    return (1);
      temp = temp->next;
    }
  if (temp->burn == 0)
    if (temp->select == 1)
      if (temp->line != check)
	return (1);
  return (0);
}

int		burn_select(t_match **match, int flag)
{
  t_match	*temp;

  temp = (*match);
  while (temp->next != NULL)
    {
      if (temp->burn == 0)
	if (temp->select == 1)
	  {
	    temp->burn = 1;
	    flag = 42;
	  }
      temp = temp->next;
    }
  if (temp->burn == 0)
    if (temp->select == 1)
      {
	temp->burn = 1;
	flag = 42;
      }
  if (temp->select == 1)
    {
      temp->burn = 1;
      flag = 42;
    }
  return (flag);
}
