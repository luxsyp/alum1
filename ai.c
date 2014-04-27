/*
** ai.c for ai_alum in /u/all/nguyen_7/cu/rendu/dirtest/alum_++/bin
** 
** Made by julien nguyen-duy
** Login   <nguyen_7@epitech.net>
** 
** Started on  Thu Feb 11 17:24:27 2010 julien nguyen-duy
** Last update Thu Feb 11 18:43:02 2010 julien nguyen-duy
*/

#include "my.h"
#include <time.h>
#include <unistd.h>

t_match		*play_last_line(t_match *match)
{
  t_match	*temp;
  int		nb_match;

  nb_match = match_count(match);
  temp = match;
  if (nb_match == 1)
    {
      match = play_2match(match, nb_match);
      return (match);
    }
  while (temp->next != NULL && nb_match != 1)
    {
      if (temp->burn == 0)
	{
	  temp->burn = 1;
	  nb_match--;
	}
      temp = temp->next;
    }
  if (temp->burn == 0)
    {
      temp->burn = 1;
      nb_match--;
    }
  return (match);
}

int		search_line(t_match *match, int the_line)
{
  t_match	*temp;
  int		check;

  check = 0;
  temp = match;
  while (temp->next != NULL)
    {
      if (temp->burn == 1)
	temp = temp->next;
      else
	if (temp->line != check)
	  {
	    check = temp->line;
	    the_line--;
	  }
      if (the_line == 0)
	return (check);
      temp = temp->next;
    }
  check = temp->line;
  the_line--;
  if (the_line == 0)
    return (check);
  return (1);
}

int		line_to_play(t_match *match, int nb_line)
{
  int		the_line;
  int		check;

  check = 0;
  the_line = 0;
  srand(time(NULL) * getpid());
  while (the_line == 0)
    the_line = rand() % (nb_line);
  if (nb_line == 2)
    {
      check = two_last_line(match, nb_line);
      return (check);
    }
  check = search_line(match, the_line);
  return (check);
}

int		rand_match(t_match *match, int the_line)
{
  t_match	*temp;
  int		nbr;
  int		nb_to_play;

  nbr = 0;
  nb_to_play = 0;
  temp = match;
  while (temp->next != NULL)
    {
      if (temp->line == the_line)
	if (temp->burn == 0)
	  nbr++;
      temp = temp->next;
    }
  if (temp->line == the_line)
    if (temp->burn == 0)
      nbr++;
  srand(time(NULL) * getpid());
  if (nbr == 1)
    return (1);
  else
    while (nb_to_play == 0)
      nb_to_play = rand() % (nbr);
  return (nb_to_play);
}

t_match		*cpu_playing(t_match *match, int line, int nb_match)
{
  t_match	*temp;

  temp = match;
  while (nb_match > 0 && temp->next != NULL)
    {
      if (temp->line == line)
	if (temp->burn == 0)
	  {
	    temp->burn = 1;
	    nb_match--;
	  }
      temp = temp->next;
    }
  if (temp->line == line && nb_match > 0)
    if (temp->burn == 0)
      {
	temp->burn = 1;
	nb_match--;
      }
  return (match);
}

