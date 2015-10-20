/*
** map.c for Map in /home/hoerte_f/rendu/PSU_2014_lemipc
** 
** Made by Francois Hoertel
** Login   <hoerte_f@epitech.net>
** 
** Started on  Wed Mar  4 20:57:25 2015 Francois Hoertel
** Last update Sat Mar  7 18:42:07 2015 Francois Hoertel
*/

#include "lemipc.h"

void	init_map(t_util *util)
{
  int	i;

  i = 0;
  while (i < MAP_X * MAP_Y)
    {
      util->addr[i] = '0';
      i++;
    }
  util->addr[i] = '\0';
}
