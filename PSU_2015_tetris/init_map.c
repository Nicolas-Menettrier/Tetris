/*
** init_map.c for init_map in /home/pinta_a/rendu/TETRIS/last
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Thu Mar 17 17:51:25 2016 pinta_a
** Last update Thu Mar 17 20:45:56 2016 pinta_a
*/

#include <stdlib.h>
#include "struct.h"
#include "proto.h"

void	fill_tmp(int **map, int height, int width)
{
  int	i;
  int	j;

  i = 0;
  while (i < height)
    {
      j = 0;
      while (j < width)
	{
	  if (i == 0 || i == height - 1)
	    map[i][j] = 1;
	  else if (j == 0 || j == width - 1)
	    map[i][j] = 1;
	  j = j + 1;
	}
      i = i + 1;
    }
}

int	**malloc_map(int height, int width)
{
  int	**map;
  int	i;
  int	j;

  i = 0;
  if ((map = malloc(sizeof(int *) * height)) == NULL)
    return (NULL);
  while (i < height)
    {
      j = 0;
      if ((map[i] = malloc(sizeof(int) * width)) == NULL)
	return (NULL);
      while (j < width)
	{
	  map[i][j] = 0;
	  j = j + 1;
	}
      i = i + 1;
    }
  return (map);
}
