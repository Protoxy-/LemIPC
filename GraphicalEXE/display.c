/*
** display.c for display in /home/hoerte_f/rendu/PSU_2014_lemipc
** 
** Made by Francois Hoertel
** Login   <hoerte_f@epitech.net>
** 
** Started on  Mon Mar  2 10:45:01 2015 Francois Hoertel
** Last update Sat Mar  7 20:13:12 2015 Francois Hoertel
*/

#include "lemipc.h"

void	wrt_str(char *str)
{
  write(1, str, strlen(str));
}

void	display_map(char *map)
{
  char	chk;
  int	i;
  int	j;

  i = 0;
  while (i < MAP_Y + 2)
    {
      j = 0;
      while (j < MAP_X)
	{
	  if (i != 0 && i != MAP_Y + 1)
	    chk = map[(i - 1) * MAP_X + j];
	  write(1, (j == 0 ? "|" : "-"), 1);
	  if (i == 0 || i == MAP_Y + 1)
	    write(1, "-", 1);
	  if (i != 0 && i != MAP_Y + 1)
	    write(1, (chk == '0' ? " " : &chk), 1);
	  j++;
	}
      write(1, "|", 1);
      write(1, "\n", 1);
      i++;
    }
  usleep(REFRESH);
}

void	display_stat(char *map, int nb_ply, int nb_team)
{
  int	team_adv;
  int	high;
  int	chk;
  int	i;

  high = 0;
  i = 0;
  while (i < NB_TEAM)
    {
      if ((chk = count_player(map, '1' + i)) == high)
	{
	  team_adv = 0;
	  break ;
	}
      team_adv = (chk > high ? i + 1 : team_adv);
      high = (chk > high ? chk : high);
      i++;
    }
  printf("[ Nb player : %d | Nb team : %d | ", nb_ply, nb_team);
  if (team_adv != 0)
    printf("The team %d has the advantage ]\n", team_adv);
  else
    printf("All team are equally ]\n");
}

void	display(char *map, t_disp *disp)
{
  int	start;
  int	nb_ply;
  int	nb_team;
  char	team_win;

  start = 0;
  while (42)
    {
      if ((nb_team = count_team(map)) == 1)
	team_win = get_last_team(map);
      nb_ply = count_player(map, 'a');
      start = (nb_ply >= NB_PLAY ? 1 : start);
      if (nb_ply < NB_PLAY && start == 0)
	wrt_str("-{ You have to put more player for start the game. }-\n");
      else
	wrt_str("-{ The Game is running ! }-\n");
      display_stat(map, nb_ply, nb_team);
      display_map(map);
      display_sdl(map, disp);
      if (nb_ply == 1 && start == 1)
	{
	  printf("The team %d Win !!!!\n", team_win - '0');
	  break;
	}
    }
}
