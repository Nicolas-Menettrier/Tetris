/*
** main.c for main in /Users/menett_a/Modules/CprogElem/CPE_2015_tetris/PSU_2015_tetris
**
** Made by menett_a
** Login   <menett_a@epitech.eu>
**
** Started on  Tue Mar 15 22:13:15 2016 menett_a
** Last update Sun Mar 20 20:30:52 2016 Nicolas Menettrier
*/

#include <curses.h>
#include <term.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include "proto.h"

int	init_term(char **env, t_loop *loop, int argc, char **argv)
{
  char	*term;
  char	*str;
  int	err;

  if (init_other(argv, "--help", NULL))
    return(my_help(argv[0]));
  term = my_term(env);
  if (setupterm(term, 1, &err) == -1)
    return (1);
  str = tigetstr("smkx");
  if (str != 0)
    tputs(str, 1, my_putcherr);
  if (init_main(loop, argv, argc) || init_tetriminos(loop))
    return (1);
  my_error(loop);
  sort_tetrimino(loop);
  if (loop->debug == 1)
    my_debug(loop);
  loop->map = malloc_map(loop->ini.game.height + 2, loop->ini.game.width + 2);
  loop->tmp = malloc_map(loop->ini.game.height + 2, loop->ini.game.width + 2);
  loop->_tmp = malloc_map(loop->ini.game.height + 2, loop->ini.game.width + 2);
  if (loop->map == NULL || loop->tmp == NULL)
    return (1);
  fill_tmp(loop->tmp, loop->ini.game.height + 2, loop->ini.game.width + 2);
  return (0);
}

int		main(int argc, char **argv, char **env)
{
  t_loop	loop;
  char		buff[10];

  loop.pos.x = 0;
  loop.pos.y = 0;
  if (init_term(env, &loop, argc, argv) == 1)
    return (1);
  if (my_set_term(&loop, 0) == -1)
    return (1);
  while (loop.debug == 1 && read(0, buff, 10) == 0);
  if (my_set_term(&loop, 1) == -1)
    return (1);
  main_loop(&loop);
  return (0);
}
