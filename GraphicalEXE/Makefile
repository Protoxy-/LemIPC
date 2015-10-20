##
## Makefile for LemiPC in /home/hoerte_f/rendu/PSU_2014_lemipc
## 
## Made by Francois Hoertel
## Login   <hoerte_f@epitech.net>
## 
## Started on  Mon Mar  2 09:18:26 2015 Francois Hoertel
## Last update Sun Mar  8 22:52:49 2015 Francois Hoertel
##

NAME	= lemipc

SRC	= err_sys.c \
	  main.c \
	  game_init.c \
	  game.c \
	  check_map.c \
	  lock_map.c \
	  map.c \
	  display.c \
	  path_finding.c \
	  player.c \
	  display_SDL.c

CFLAGS  = -Werror -Wextra -Wall -W -I.
LDFLAGS = -lSDLmain -lSDL

OBJ 	= $(SRC:.c=.o)

CC 	= gcc

RM	= rm -f

$(NAME):	 $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)


clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME) $(LN_NAME)

re:		fclean all

.PHONY:		all clean re fclean
