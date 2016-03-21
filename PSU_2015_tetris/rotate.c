/*
** rotate.c for rotate in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Fri Mar 18 18:21:05 2016 pinta_a
** Last update Sun Mar 20 23:20:14 2016 pinta_a
*/

#include "struct.h"
#include "proto.h"

void	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}

void	my_free(int **map, int height)
{
  int	i;

  i = 0;
  while (i < height)
    {
      free(map[i]);
      i = i + 1;
    }
  free(map);
}

int	**my_malloc(int width, int height)
{
  int	**new;
  int	i;

  i = 0;
  if ((new = malloc(sizeof(int *) * height)) == NULL)
    return (NULL);
  while (i < height)
    {
      if ((new[i] = malloc(sizeof(int) * width)) == NULL)
	return (NULL);
      i = i + 1;
    }
  return (new);
}

int	**rotate_left(int **form, int *width, int *height)
{
  int	**new;
  int	i;
  int	j;

  if ((new = my_malloc(*height, *width)) == NULL)
    return (NULL);
  j = 0;
  while (j < *width)
    {
      i = 0;
      while (i < *height)
	{
	  new[(*width - 1) - j][i] = form[i][j];
	  i = i + 1;
	}
      j = j + 1;
    }
  my_free(form, *height);
  my_swap(width, height);
  return (new);
}

int	**rotate_right(int **form, int *width, int *height)
{
  int	**new;
  int	i;
  int	j;

  if ((new = my_malloc(*height, *width)) == NULL)
    return (NULL);
  j = 0;
  while (j < *width)
    {
      i = 0;
      while (i < *height)
	{
	  new[j][(*height - 1) - i] = form[i][j];
	  i = i + 1;
	}
      j = j + 1;
    }
  my_free(form, *height);
  my_swap(width, height);
  return (new);
}
