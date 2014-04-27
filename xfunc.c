/*
** xfunc.c for lol in /u/all/nguyen_7/public/alum-1
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sat Feb 13 16:41:13 2010 damien locque
** Last update Sat Feb 13 16:43:55 2010 damien locque
*/

#include	"my.h"
#include	<unistd.h>
#include	<stdlib.h>

void		my_puterror(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  xwrite(2, str, i);
}

int		xwrite(int d, void *buf, int nbytes)
{
  if (write(d, buf, nbytes) == -1)
    {
      write(2, "Can't write\n", 12);
      return (-1);
    }
  return (nbytes);
}

void		*xmalloc(size_t size)
{
  void		*str;

  if ((str = malloc(size)) == 0)
    {
      my_puterror("Memory allocation failure - Exit\n");
      exit(EXIT_FAILURE);
    }
  return (str);
}
