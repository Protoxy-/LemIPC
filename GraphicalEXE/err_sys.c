/*
** err_sys.c for Error syteme in /home/hoerte_f/rendu/PSU_2014_lemipc
** 
** Made by Francois Hoertel
** Login   <hoerte_f@epitech.net>
** 
** Started on  Tue Mar  3 18:44:35 2015 Francois Hoertel
** Last update Sun Mar  8 22:54:58 2015 Francois Hoertel
*/

#include "lemipc.h"

int	err_msg(char *msg)
{
  if (msg[0] == ':')
    printf("Error %s\n", msg);
  else
    printf("%s\n", msg);
  return (-1);
}

void	*verr_msg(char *msg)
{
  err_msg(msg);
  return (NULL);
}

void	exit_err(char *msg)
{
  if (msg[0] == ':')
    {
      printf("Error %s\n", msg);
      exit(EXIT_FAILURE);
    }
  else
    {
      printf("%s\n", msg);
      exit(EXIT_SUCCESS);
    }
}
