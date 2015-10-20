/*
** lock_map.c for Lock in /home/hoerte_f/rendu/PSU_2014_lemipc
** 
** Made by Francois Hoertel
** Login   <hoerte_f@epitech.net>
** 
** Started on  Tue Mar  3 21:13:01 2015 Francois Hoertel
** Last update Sat Mar  7 18:07:44 2015 Francois Hoertel
*/

#include	"lemipc.h"

void		lock(t_util *util)
{
  util->sops.sem_num = 0;
  util->sops.sem_flg = 0;
  util->sops.sem_op = -1;
  semop(util->sem_id, &(util->sops), 1);
}

void		unlock(t_util *util)
{
  util->sops.sem_num = 0;
  util->sops.sem_flg = 0;
  util->sops.sem_op = 1;
  semop(util->sem_id, &(util->sops), 1);
}
