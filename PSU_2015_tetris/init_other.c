/*
** init_other.c<3> for init_other in /home/pinta_a/rendu/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Wed Mar 16 21:47:36 2016 pinta_a
** Last update Wed Mar 16 21:51:05 2016 pinta_a
*/

#include "proto.h"

int		init_other(char **argv, char *one, char *two)
{
  int		i;

  i = 0;
  while (argv[i] != NULL)
    {
      if (my_strcmp(argv[i], one))
	return (1);
      if (two != NULL && my_strcmp(argv[i], two))
	return (1);
      i = i + 1;
    }
  return (0);
}
