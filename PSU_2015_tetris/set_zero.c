/*
** set_zero.c for set_zero in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
**
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
**
** Started on  Fri Mar 18 18:28:12 2016 pinta_a
** Last update Sun Mar 20 22:52:28 2016 pinta_a
*/

#include "struct.h"
#include "proto.h"

void	set_zero(int **map, t_pos *pos, t_form *form)
{
  int	i;
  int	j;

  i = pos->y;
  while (i - pos->y < form->height)
    {
      j = pos->x;
      while (j - pos->x < form->width)
	{
	  if (form->form[i - pos->y][j - pos->x] == 1)
	    map[i][j] = 0;
	  j = j + 1;
	}
      i = i + 1;
    }
}

int	check_collision(int **map, int width, int height)
{
  int	i;
  int	j;

  i = 0;
  while (i < height + 2)
    {
      j = 0;
      while (j < width + 2)
	{
	  if (map[i][j] > 1)
	    return (1);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (0);
}

void	add_tab(int **map, t_form *form, t_pos *pos)
{
  int	i;
  int	j;

  i = pos->y;
  while (i - pos->y < form->height)
    {
      j = pos->x;
      while (j - pos->x < form->width)
	{
	  if (form->form[i - pos->y][j - pos->x] == 1)
	    map[i][j] = map[i][j] + 1;
	  if (map[i][j] > 1)
	    return ;
	  j = j + 1;
	}
      i = i + 1;
    }
}

void	set_map(int **map, t_pos *pos, t_form *form, int color)
{
  int	i;
  int	j;

  i = pos->y;
  while (i - pos->y < form->height)
    {
      j = pos->x;
      while (j - pos->x < form->width)
	{
	  if (form->form[i - pos->y][j - pos->x] == 1)
	    map[i][j] = color;
	  j = j + 1;
	}
      i = i + 1;
    }
}
