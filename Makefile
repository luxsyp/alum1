##
## Makefile for mk_alum1 in /u/all/nguyen_7/cu/rendu/dirtest/alum/SDL/bin
##
## Made by julien nguyen-duy
## Login   <nguyen_7@epitech.net>
##
## Started on  Wed Feb 10 14:43:40 2010 julien nguyen-duy
## Last update Mon Feb 14 12:21:08 2011 damien locque
##

NAME	= alum1
SRCS	= ai.c		\
	  ai2.c		\
	  match_func.c	\
	  check_space.c	\
	  static.c	\
	  init.c	\
	  free_all.c	\
	  try_win.c	\
	  affpvp.c	\
	  aff.c		\
	  pvp.c		\
	  xfunc.c	\
	  xfuncSDL.c	\
	  main.c

RM	= rm -f

OBJS	= $(SRCS:.c=.o)
CC	= gcc

LDFLAGS += -I/usr/local/include/SDL -I/usr/local/include -D_GNU_SOURCE=1 -D_REENTRANT -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL -pthread -lSDL_image
CFLAGS	= -I. -W -Wall -pedantic -ansi -O2

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

