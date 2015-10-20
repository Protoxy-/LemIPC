/*
** main.c for lemiPC in /home/wentz/Rendu/PSU_2014_lemipc/
**
** Made by scott wentz
** Login   <wentz_s@epitech.eu>
**
** Started on  Tue Mar  3 15:08:29 2015 scott wentz
** Last update Sun Mar  8 02:25:27 2015 Francois Hoertel
*/

#include "lemipc.h"

int			main()
{
  struct timeval	tv;
  struct timezone	tz;
  t_util		*util;
  char			*str;

  gettimeofday(&tv, &tz);
  if (!(util = malloc(sizeof(t_util))))
    return (err_msg(": malloc fail"));
  if ((str = getenv("PWD")) == NULL)
    return (err_msg(": getenv fail"));
  srand(tv.tv_usec);
  if (!(util->key = ftok(str, 0)) == -1)
    return (err_msg(": ftok fail"));
  util->shm_id = shmget(util->key, (sizeof(char) * (MAP_X * MAP_Y)),
			SHM_R | SHM_W);
  if (util->shm_id == -1)
    first_step(util);
  else
    other_player(util);
  return (0);
}
