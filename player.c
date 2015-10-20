/*
** create_player.c for crt player in /home/hoerte_f/rendu/PSU_2014_lemipc
**
** Made by Francois Hoertel
** Login   <hoerte_f@epitech.net>
**
** Started on  Mon Mar  2 09:51:07 2015 Francois Hoertel
** Last update Sat Mar  7 18:55:54 2015 Francois Hoertel
*/

#include "lemipc.h"

int	player_move(t_player *ply, char *map)
{
  int	dir;
  int	mov[2];

  if ((dir = get_dir(ply, 0)) == 0)
    return (0);
  mov[0] = ply->x + (dir == -1 || dir == 1 ? dir : 0);
  mov[1] = ply->y + (dir == -2 || dir == 2 ? dir / 2 : 0);
  map[(ply->y * MAP_X) + ply->x] = '0';
  if (map[(mov[1] * MAP_X) + mov[0]] == '0')
    {
      ply->x = mov[0];
      ply->y = mov[1];
      map[(ply->y * MAP_X) + ply->x] = ply->team;
    }
  else if (go_straight(ply, map, dir) == 0)
    {
      map[(ply->y * MAP_X) + ply->x] = ply->team;
      return (0);
    }
  return (1);
}

void	player_dead(t_util *util, t_player *ply)
{
  if (count_player(util->addr, 'a') == 1)
    {
      usleep(REFRESH);
      semctl(util->sem_id, IPC_RMID, 0);
      semctl(util->sem_id, IPC_RMID, 0);
      shmctl(util->shm_id, IPC_RMID, 0);
      if (shmdt(util->addr) == -1)
        err_msg(": shmdt failed");
    }
  else
    {
      lock(util);
      util->addr[ply->y * MAP_X + ply->x] = '0';
      unlock(util);
    }
}
