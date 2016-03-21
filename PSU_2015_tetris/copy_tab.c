/*
** copy_tab.c for copy_tab in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Sat Mar 19 17:23:35 2016 pinta_a
** Last update Sat Mar 19 18:19:31 2016 pinta_a
*/

#include "proto.h"

void	my_copy_tab(int **map, int **tmp, int width, int height)
{
  int	i;
  int	j;

  i = 0;
  while (i < height + 2)
    {
      j = 0;
      while (j < width + 2)
	{
	  tmp[i][j] = map[i][j];
	  j = j + 1;
	}
      i = i + 1;
    }
}
