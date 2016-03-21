/*
** init_pars.c for init_pars in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Sat Mar 19 16:53:53 2016 pinta_a
** Last update Sat Mar 19 17:03:35 2016 pinta_a
*/

#include "proto.h"

void	test_opt(t_init *ini, char **argv, int *i, int *j)
{
  if (my_strcmp(ini->opt_one[*j], argv[*i]) && argv[*i + 1] != NULL)
    {
      ini->opt[*j] = argv[*i + 1];
      if (argv[*i + 1][0] == '\0')
      	*j = 7;
      else
	*j = 0;
      *i = *i + 2;
    }
  else if (my_strcmp_equal(ini->opt_two[*j], argv[*i]))
    {
      if ((ini->opt[*j] = opt_key(argv[*i])) ==  NULL)
	*j = 7;
      else
	*j = 0;
      *i = *i + 1;
    }
  else
    *j = *j + 1;
}

int	_init_pars(t_init *ini, char **argv, int *i)
{
  int	j;

  j = 1;
  while (j < 7 && j >= 1)
    test_opt(ini, argv, i, &j);
  if (j == 7)
    return (1);
  return (0);
}

int	check_pars(t_loop *loop, char **argv, int *i)
{
  if (my_strcmp(argv[*i], "-l"))
    {
      if (argv[*i + 1] == NULL)
	return (my_help(argv[0]));
      *i = *i + 2;
    }
  else if (my_strcmp_equal(argv[*i], "--level=")
	   || my_strcmp_equal(argv[*i], "--map-size="))
    *i = *i + 1;
  else if (my_strcmp(argv[*i], "-d") || my_strcmp(argv[*i], "--debug"))
    {
      loop->debug = 1;
      *i = *i + 1;
    }
  else if (my_strcmp(argv[*i], "-w") || my_strcmp(argv[*i], "--without-next"))
    {
      loop->ini.game.next = 0;
      *i = *i + 1;
    }
  else if (_init_pars(&loop->ini, argv, i))
    return (my_help(argv[0]));
  return (0);
}

int	init_pars(t_loop *loop, char **argv, int argc)
{
  int	i;

  i = 1;
  while (i < argc)
    {
      if (check_pars(loop, argv, &i))
	return (1);
    }
  return (0);
}
