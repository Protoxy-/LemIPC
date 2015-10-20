/*
** check_map.c for map in /home/hoerte_f/rendu/PSU_2014_lemipc
** 
** Made by Francois Hoertel
** Login   <hoerte_f@epitech.net>
** 
** Started on  Mon Mar  2 11:41:48 2015 Francois Hoertel
** Last update Sat Mar  7 18:42:12 2015 Francois Hoertel
*/

#include "lemipc.h"

int	count_player(char *map, char team)
{
  int	nb;
  int	i;

  nb = 0;
  i = 0;
  while (i < MAP_X * MAP_Y)
    {
      if (team == 'a' && map[i] != '0')
	nb++;
      if (team != 'a' && map[i] == team)
	nb++;
      i++;
    }
  return (nb);
}

int	count_team(char *map)
{
  int	nb;
  int	i;

  nb = 0;
  i = 0;
  while (i < NB_TEAM)
    {
      if (count_player(map, i + '1') > 0)
        nb++;
      i++;
    }
  return (nb);
}

char	get_last_team(char *map)
{
  int	i;

  i = 0;
  while (i < MAP_X * MAP_Y)
    {
      if (map[i] != '0')
	return (map[i]);
      i++;
    }
  return (0);
}

int	is_attacked(char *map, char team, int x, int y)
{
  int	i;
  int	j;
  int	n;

  n = 0;
  i = (y - 1 < 0 ? 0 : y - 1);
  while (i < y + 3 && i < MAP_Y)
    {
      j = (x - 1 < 0 ? 0 : x - 1);
      while (j <  x + 3 && i < MAP_X)
	{
	  if (map[(i * MAP_X) + j] != '0' && map[(i * MAP_X) + j] != team)
	    n++;
	  j++;
	}
      i++;
    }
  return (n);
}
