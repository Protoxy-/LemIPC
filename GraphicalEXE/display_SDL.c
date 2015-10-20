/*
** SDL_display.c for SDL in /home/hoerte_f/rendu/PSU_2014_philo
** 
** Made by Francois Hoertel
** Login   <hoerte_f@epitech.net>
** 
** Started on  Wed Feb 25 11:02:24 2015 Francois Hoertel
** Last update Sun Mar  8 00:29:43 2015 Francois Hoertel
*/

#include "lemipc.h"

t_disp		*init_sdl()
{
  t_disp	*disp;

  if ((disp = malloc(sizeof(t_disp))) == NULL)
    err_msg("SDL : malloc fail");
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    err_msg("SDL : Can't init");
  disp->win = SDL_SetVideoMode(MAP_X * 16, MAP_Y * 16, 32, SDL_HWSURFACE);
  if (disp->win == NULL)
    err_msg("SDL : Could not create window");
  SDL_WM_SetCaption("LemiPC", "LemiPC");
  disp->winP.x = 0;
  disp->winP.y = 0;
  if ((disp->monster = SDL_LoadBMP("Data/monster.bmp")) == NULL)
    err_msg("SDL : Can't load the philosophe image");
  if ((disp->back = SDL_LoadBMP("Data/background.bmp")) == NULL)
    err_msg("SDL : Can't load the background image");
  disp->monsterP.x = 0;
  disp->monsterP.y = 0;
  disp->monsterP.w = 16;
  disp->monsterP.h = 16;
  return (disp);
}

void		show_monster(t_disp *d, int team, int x, int y)
{
  d->monsterP.x = ((team / 16) * 16) * 2;
  d->monsterP.y = (team % 16) * 16;
  d->winP.x = x * 16;
  d->winP.y = y * 16;
  if (SDL_BlitSurface(d->monster, &d->monsterP, d->win, &d->winP) != 0)
    err_msg("SDL : Can't blit the surface");
}

void		display_sdl(char *map, t_disp *disp)
{
  int		team;
  int		x;
  int		y;

  if (SDL_BlitSurface(disp->back, 0, disp->win, 0) != 0)
    err_msg("SDL : Can't blit the surface");
  y = 0;
  while (y < MAP_Y)
    {
      x = 0;
      while (x < MAP_X)
	{
	  team = map[(y * MAP_X) + x] - '0';
	  if (team != 0)
	    show_monster(disp, team, x, y);
	  x++;
	}
      y++;
    }
  if (SDL_Flip(disp->win) == -1)
    err_msg("SDL : Can't flip");
}
