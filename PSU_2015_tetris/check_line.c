/*
** check_line.c for check_line in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Sat Mar 19 19:12:22 2016 pinta_a
** Last update Sun Mar 20 22:42:10 2016 pinta_a
*/

#include "proto.h"

void	copy_line(int *dest, int *src, int size)
{
  int	i;

  i = 1;
  while (i < size)
    {
      dest[i] = src[i];
      i = i + 1;
    }
}

void	down_tab(t_loop *data, int i)
{
  while (i > 1)
    {
      copy_line(data->tmp[i], data->tmp[i - 1], data->ini.game.width + 1);
      copy_line(data->map[i], data->map[i - 1], data->ini.game.width + 1);
      i = i - 1;
    }
}

void	_check_line(t_loop *data, int *j, int *x)
{
  data->ini.game.line = data->ini.game.line + 1;
  if (data->ini.game.line % 10 == 0)
    data->ini.game.level = data->ini.game.level + 1;
  data->ini.game.score = data->ini.game.score + 10 * *x;
  *x = *x + 1;
  *j = 1;
}

void	check_line(t_loop *data)
{
  int	i;
  int	j;
  int	x;

  i = 1;
  x = 1;
  while (i < data->ini.game.height + 1)
    {
      j = 1;
      while (data->tmp[i][j] == 1 && j < data->ini.game.width + 1)
	j = j + 1;
      if (j == data->ini.game.width + 1)
	{
	  _check_line(data, &j, &x);
	  while (j < data->ini.game.width + 1)
	    {
	      data->tmp[i][j] = 0;
	      data->map[i][j] = 0;
	      j = j + 1;
	    }
	  if (i > 1)
	    down_tab(data, i);
	}
      i = i + 1;
    }
}
