
/*
** pommier.c for pommier in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
**
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
**
** Started on  Thu Mar 17 22:51:33 2016 pinta_a
** Last update Sun Mar 20 23:46:17 2016 pinta_a
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

char	*init_window(t_loop *data)
{
  int	width;
  int	height;

  if ((width = max_dim(data, 1) + 2) < 8)
    width = 8;
  height = max_dim(data, 2) + 2;
  if (initscr() == NULL)
    return ("Error while initializing screen\n");
  if ((data->win.stat = newwin(22, 30, 0, 0)) == NULL)
    return ("Error while getting the stat window\n");
  if ((data->win.game =
       newwin(data->ini.game.height + 2,
	      data->ini.game.width + 2, 0, 35)) == NULL)
    return ("Error while getting the game window\n");
  if ((data->win.next =
       newwin(height, width, 0, 54 + data->ini.game.width)) == NULL)
    return ("Error while getting the next window\n");
  return (NULL);
}

void	init_pos(t_loop *data)
{
  int	x;

  x = 1;
  while (x < data->ini.game.width / 2
	 && x + data->actual.width < data->ini.game.width)
    x = x + 1;
  data->pos.x = x;
  data->pos.y = 1;
}

int	init_new_form(t_loop *data, int opt)
{
  if (opt == 0)
    {
      my_copy_form(data, &data->form[rand() % data->nb_form], &data->actual);
      while (data->actual.error == 1)
	my_copy_form(data, &data->form[rand() % data->nb_form], &data->actual);
      my_copy_form(data, &data->form[rand() % data->nb_form], &data->next);
      while (data->next.error == 1)
	my_copy_form(data, &data->form[rand() % data->nb_form], &data->next);
    }
  if (opt == 1)
    {
      check_line(data);
      my_copy_form(data, &data->next, &data->actual);
      my_copy_form(data, &data->form[rand() % data->nb_form], &data->next);
      while (data->next.error == 1)
	my_copy_form(data, &data->form[rand() % data->nb_form], &data->next);
    }
  init_pos(data);
  add_tab(data->tmp, &data->actual, &data->pos);
  set_map(data->map, &data->pos, &data->actual, data->actual.color);
  if (check_collision(data->tmp, data->ini.game.width,
		      data->ini.game.height)
      || my_view(data))
    return (1);
  return (0);
}

int	init_first_tetri(t_loop *data)
{
  char	*str;

  if ((str = init_window(data)) != NULL)
    return (my_putsterr(str));
  my_color(data);
  srand(time(NULL));
  if (init_new_form(data, 0))
    return (1);
  init_ptr(data->ptr);
  return (0);
}

int	main_loop(t_loop *data)
{
  int	size;

  size = 0;
  if (init_main_loop(data))
    quit_game(data);
  while (game_over(data) == 0)
    {
      data->timer = 0;
      while (data->timer < 40)
	poirier_main(data, size);
      if (drop_tetri(data) && init_new_form(data, 1))
  	quit_game(data);
      if (my_view(data))
	quit_game(data);
    }
  return (0);
}
