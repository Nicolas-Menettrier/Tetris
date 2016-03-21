/*
** init_level.c for init_level in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Sat Mar 19 16:13:12 2016 pinta_a
** Last update Sat Mar 19 16:41:29 2016 pinta_a
*/

#include "proto.h"

void	init_level(t_init *ini, char **argv)
{
  int	i;
  int	j;

  i = 1;
  while (argv[i] != NULL)
    {
      if (my_strcmp_equal(argv[i], ini->opt_two[0]) == 1)
	{
	  j = 8;
	  ini->game.level = my_getnbr_x(argv[i], 1, &j);
	}
      if (my_strcmp(argv[i], ini->opt_one[0]) == 1)
	{
	  if (my_getnbr_a(argv[i + 1], &ini->game.level) == 1)
	    ini->game.level = 1;
	}
      i = i + 1;
    }
  if (ini->game.level < 1)
    ini->game.level = 1;
}
