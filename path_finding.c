/*
** path_finding.c for Player Path Finding in /home/hoerte_f/rendu/PSU_2014_lemipc
** 
** Made by Francois Hoertel
** Login   <hoerte_f@epitech.net>
** 
** Started on  Sat Mar  7 14:30:20 2015 Francois Hoertel
** Last update Sat Mar  7 18:19:18 2015 Francois Hoertel
*/

#include "lemipc.h"

int	get_target(t_player *ply, char *map, int j, int k)
{
  if (map[(j * MAP_X) + k] != '0' && map[(j * MAP_X) + k] != ply->team)
    {
      ply->target[0] = k;
      ply->target[1] = j;
      return (1);
    }
  return (0);
}

void	nearest_ennemie(t_player *ply, char *map)
{
  int	i;
  int	j;
  int	k;

  i = 1;
  while (i < (MAP_X >= MAP_Y ? MAP_X : MAP_Y))
    {
      j = (ply->y - i < 0 ? 0 : ply->y - i);
      while (j <= ply->y + (i * 2) && j < MAP_Y)
	{
	  k = (ply->x - i < 0 ? 0 : ply->x - i);
	  while (k <= ply->x + (i * 2) && k < MAP_X)
	    {
	      if (get_target(ply, map, j, k) == 1)
		return ;
	      k++;
	    }
	  j++;
	}
      i++;
    }
  ply->target[0] = ply->x;
  ply->target[1] = ply->y;
}

int	get_dir(t_player *ply, int ax)
{
  int	x;
  int	y;

  x = ply->target[0] - ply->x;
  y = ply->target[1] - ply->y;
  if (x >= -1 && x <= 1 && y >= -1 && y <= 1)
    return (0);
  if (((x < 0 ? x * (-1) : x) >= (y < 0 ? y * (-1) : y) && ax == 0) || ax == 1)
    {
      if (x < 0)
	return (-1);
      return (1);
    }
  if (((x < 0 ? x * (-1) : x) < (y < 0 ? y * (-1) : y) && ax == 0) || ax == 2)
    {
      if (y < 0)
	return (-2);
      return (2);
    }
  return (0);
}

int	go_straight(t_player *ply, char *map, int dir)
{
  int	sec_dir;
  int	mov;

  if (dir == -1 || dir == 1)
    {
      mov = ply->y + (sec_dir = get_dir(ply, 2)) / 2;
      if (mov >= 0 && mov < MAP_Y && map[(mov * MAP_X) + ply->x] == '0')
	map[((ply->y = mov) * MAP_X) + ply->x] = ply->team;
      else
	return (0);
    }
  if (dir == -2 || dir == 2)
    {
      mov = ply->x + (sec_dir = get_dir(ply, 1));
      if (mov >= 0 && mov < MAP_X && map[ply->y * MAP_X + mov] == '0')
	map[ply->y * MAP_X + (ply->x = mov)] = ply->team;
      else
	return (0);
    }
  return (1);
}
