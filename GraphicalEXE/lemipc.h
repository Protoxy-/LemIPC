/*
** lemipc.h for lemiPC in /home/wentz/Rendu/PSU_2014_lemipc/
**
** Made by scott wentz
** Login   <wentz_s@epitech.eu>
**
** Started on  Tue Mar  3 15:08:57 2015 scott wentz
** Last update Mon Mar  9 21:56:25 2015 Francois Hoertel
*/

#ifndef LEMIPC_H_
# define LEMIPC_H_

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <SDL/SDL.h>

#include "display.h"

# define MAP_X 100
# define MAP_Y 60
# define NB_TEAM 10
# define NB_PLAY 100
# define REFRESH 1000
# define MOVE_TM 50000
# define WAIT_LM 5

typedef struct	s_util
{
  key_t		key;
  int		shm_id;
  int		sem_id;
  int		msg_id;
  char		*addr;
  struct sembuf	sops;
  int		id;
  int		cycle;
  int		player_nb;
}		t_util;

typedef struct	s_player
{
  int		x;
  int		y;
  int		*target;
  char		team;
  int		state;
}		t_player;

int	get_param(t_util *, char **);
int	init_default_value(t_util *);
int	err_msg(char *);
void	*verr_msg(char *);
void	exit_err(char *);
void	lock(t_util *);
void	unlock(t_util *);
void	init_map(t_util *);
int	new_player(t_util *);
int	first_step(t_util *);
int	other_player(t_util *);
int	count_player(char *, char);
int	count_team(char *);
char	get_last_team(char *);
int	is_attacked(char *, char, int, int);
void	wrt_str(char *);
void	display_map(char *);
void	display_stat(char *, int, int);
void	display(char *, t_disp *);
int	get_target(t_player *, char *, int, int);
void	nearest_ennemie(t_player *, char *);
int	get_dir(t_player *, int);
int	go_straight(t_player *, char *, int);
int	player_move(t_player *, char *);
void	player_dead(t_util *, t_player *);
void	game_loop(t_util *, t_player *);
void	game(t_util *, t_player *);
t_disp	*init_sdl();
void	display_sdl(char *, t_disp *);

#endif /* LEMIPC_H_ */
