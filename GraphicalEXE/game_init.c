/*
** init.c for lemiPC in /home/wentz/Rendu/PSU_2014_lemipc/
**
** Made by scott wentz
** Login   <wentz_s@epitech.eu>
**
** Started on  Tue Mar  3 15:08:43 2015 scott wentz
** Last update Sun Mar  8 18:56:04 2015 Francois Hoertel
*/

#include "lemipc.h"

int	get_loser(char *map)
{
  int	loser;
  int	lower;
  int	chk;
  int	i;

  loser = 1;
  lower = NB_TEAM;
  chk = 0;
  i = 0;
  while (i < NB_TEAM)
    {
      if ((chk = count_player(map, '1' + i)) < lower)
	{
	  lower = chk;
	  loser = i + 1;
	}
      i++;
    }
  return (loser);
}

int	new_player(t_util *util)
{
  t_player *ply;

  if (!(ply = malloc(sizeof(*ply))))
    return (err_msg(": Malloc fail"));
  if (NB_TEAM > 76)
    return (err_msg(": you have put to mutch team ! max val 76"));
  if (util->id + 1 >= MAP_X * MAP_Y)
    return (err_msg(": You have put to mutch player in one time !"));
  util->cycle = 0;
  if (!(ply->target = malloc(sizeof(int) * 2)))
    exit_err(": Malloc faild !\n");
  ply->team = '1' + (util->id < NB_PLAY ? util->id : rand()) % NB_TEAM;
  while (42)
    {
      ply->x = rand() % MAP_X;
      ply->y = rand() % MAP_Y;
      if ((util->addr)[ply->x + (ply->y * MAP_X)] == '0')
	break;
    }
  lock(util);
  util->addr[ply->x + (ply->y * MAP_X)] = ply->team;
  unlock(util);
  game(util, ply);
  return (0);
}

int	first_step(t_util *util)
{
  int	pid;

  util->id = 0;
  util->shm_id = shmget(util->key, (sizeof(char) * (MAP_X * MAP_Y)),
			IPC_CREAT | SHM_R | SHM_W);
  util->msg_id = msgget(util->key, IPC_CREAT | SHM_R | SHM_W);
  util->sem_id = semget(util->key, 1, IPC_CREAT | SHM_R | SHM_W);
  if (util->shm_id == -1 || util->msg_id == -1 ||  util->sem_id == -1)
    return (err_msg(": the creation of a shared memory fail"));
  util->addr = shmat(util->shm_id, NULL, SHM_R | SHM_W);
  init_map(util);
  semctl(util->sem_id, 0, SETVAL, 1);
  pid = fork();
  if (pid != 0)
    {
      display(util->addr, init_sdl());
      SDL_Quit();
      return (1);
    }
  if (new_player(util) == -1)
    return (-1);
  return (1);
}

int	other_player(t_util *util)
{
  util->addr = shmat(util->shm_id, NULL, SHM_R | SHM_W);
  util->id = count_player(util->addr, 'a');
  if (new_player(util) == -1)
    return (-1);
  return (0);
}
