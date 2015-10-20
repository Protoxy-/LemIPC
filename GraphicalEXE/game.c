/*
** game.c for The Game in /home/hoerte_f/rendu/PSU_2014_lemipc
** 
** Made by Francois Hoertel
** Login   <hoerte_f@epitech.net>
** 
** Started on  Wed Mar  4 21:02:34 2015 Francois Hoertel
** Last update Sun Mar  8 01:24:06 2015 Francois Hoertel
*/

#include "lemipc.h"

void	game_loop(t_util *util, t_player *ply)
{
  nearest_ennemie(ply, util->addr);
  lock(util);
  player_move(ply, util->addr);
  unlock(util);
  usleep(MOVE_TM);
}

void	game(t_util *util, t_player *ply)
{
  while ((util->player_nb = count_player(util->addr, 'a')) < NB_PLAY)
    usleep(10000);
  util->cycle = 0;
  while (42)
    {
      if (is_attacked(util->addr, ply->team, ply->x, ply->y) >= 2)
        break;
      if (count_team(util->addr) == 1)
	{
	  util->cycle++;
	  if (util->cycle >= WAIT_LM)
	    break;
	}
      else
	util->cycle = 0;
      game_loop(util, ply);
    }
  player_dead(util, ply);
}
