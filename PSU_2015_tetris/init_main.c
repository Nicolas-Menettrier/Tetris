/*
** init_main.c for init_main in /Users/menett_a/Modules/CprogElem/CPE_2015_tetris
**
** Made by menett_a
** Login   <menett_a@epitech.eu>
**
** Started on  Sat Feb 27 13:03:12 2016 menett_a
** Last update Sun Mar 20 19:21:58 2016 Nicolas Menettrier
*/

#include "proto.h"

char	*opt_key(char *key)
{
  int	i;

  i = 0;
  while (key[i] != '=' && key[i] != '\0')
    i = i + 1;
  i = i + 1;
  if (key[i] == '\0')
    return (NULL);
  return (&key[i]);
}

void	init_map(t_init *ini, char **argv)
{
  int	i;
  int	j;

  i = 1;
  while (argv[i] != NULL)
    {
      if (my_strcmp_equal(argv[i], ini->opt_two[7]) == 1)
	{
	  j = 11;
	  ini->game.width = my_getnbr_x(argv[i], 1, &j);
	  ini->game.height = my_getnbr_x(argv[i], 0, &j);
	  if (ini->game.width < 1 || ini->game.height < 1)
	    {
	      ini->game.width = 10;
	      ini->game.height = 20;
	    }
	}
      i = i + 1;
    }
}

int	init_main(t_loop *loop, char **argv, int argc)
{
  loop->debug = 0;
  loop->pause = 0;
  init_opt_one(&loop->ini);
  init_opt_two(&loop->ini);
  init_key(&loop->ini);
  init_game(&loop->ini);
  init_level(&loop->ini, argv);
  if (init_pars(loop, argv, argc))
    return (1);
  init_map(&loop->ini, argv);
  loop->ini.max = max_arg(&loop->ini);
  loop->ini.game.line = 0;
  loop->ini.game.score = 0;
  return (0);
}
