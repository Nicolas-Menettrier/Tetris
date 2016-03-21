/*
** game_view.c for game_view in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Thu Mar 17 23:34:15 2016 pinta_a
** Last update Sun Mar 20 16:29:42 2016 pinta_a
*/

#include "proto.h"

int	check_move(char *cmd, t_loop *data, int (**ptr)(t_loop *))
{
  int	save;
  int	i;

  i = 1;
  save = 0;
  while (i < 7)
    {
      if (my_strcmp(data->ini.opt[i], cmd) == 1)
	{
	  save = i;
	  i = 7;
	}
      i = i + 1;
    }
  if (data->pause == 1 && save == 6 && save != 0)
    ptr[save - 1](data);
  else if (data->pause == 0 && save != 0)
    {
      i = ptr[save - 1](data);
      return (i);
    }
  return (0);
}
