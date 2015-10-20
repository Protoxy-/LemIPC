/*
** display.h for SDL in /home/hoerte_f/rendu/PSU_2014_lemipc/SDL
** 
** Made by Francois Hoertel
** Login   <hoerte_f@epitech.net>
** 
** Started on  Sat Mar  7 22:42:13 2015 Francois Hoertel
** Last update Sat Mar  7 22:42:15 2015 Francois Hoertel
*/

#ifndef	DISPLAY_H_
# define DISPLAY_H_

typedef	struct	s_disp
{
  SDL_Surface	*win;
  SDL_Rect	winP;
  SDL_Surface	*back;
  SDL_Surface	*monster;
  SDL_Rect      monsterP;
}		t_disp;

#endif /* DISPLAY_H_ */
