/*
** move_tetri.c for move_tetri in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
**
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
**
** Started on  Fri Mar 18 17:46:45 2016 pinta_a
** Last update Sun Mar 20 23:05:36 2016 pinta_a
*/

#include <curses.h>
#include "proto.h"

int	move_left(t_loop *data)
{
  my_copy_tab(data->tmp, data->_tmp, data->ini.game.width,
	      data->ini.game.height);
  set_zero(data->_tmp, &data->pos, &data->actual);
  set_zero(data->map, &data->pos, &data->actual);
  data->pos.x = data->pos.x - 1;
  add_tab(data->_tmp, &data->actual, &data->pos);
  if (data->pos.x > 0
      && check_collision(data->_tmp, data->ini.game.width,
			 data->ini.game.height) == 0)
    my_copy_tab(data->_tmp, data->tmp, data->ini.game.width,
	     data->ini.game.height);
  else
    data->pos.x = data->pos.x + 1;
  set_map(data->map, &data->pos, &data->actual, data->actual.color);
  return (0);
}

int	move_right(t_loop *data)
{
  my_copy_tab(data->tmp, data->_tmp, data->ini.game.width,
	      data->ini.game.height);
  set_zero(data->_tmp, &data->pos, &data->actual);
  set_zero(data->map, &data->pos, &data->actual);
  data->pos.x = data->pos.x + 1;
  add_tab(data->_tmp, &data->actual, &data->pos);
  if (data->pos.x - 2 + data->actual.width < data->ini.game.width
      && check_collision(data->_tmp, data->ini.game.width,
			 data->ini.game.height) == 0)
    my_copy_tab(data->_tmp, data->tmp, data->ini.game.width,
		data->ini.game.height);
  else
    data->pos.x = data->pos.x - 1;
  set_map(data->map, &data->pos, &data->actual, data->actual.color);
  return (0);
}

int	turn_tetri(t_loop *data)
{
  my_copy_tab(data->tmp, data->_tmp, data->ini.game.width,
	      data->ini.game.height);
  set_zero(data->_tmp, &data->pos, &data->actual);
  set_zero(data->map, &data->pos, &data->actual);
  if ((data->actual.form = rotate_right(data->actual.form, &data->actual.width,
					&data->actual.height)) == NULL)
    quit_game(data);
  add_tab(data->_tmp, &data->actual, &data->pos);
  if (data->pos.y - 2 + data->actual.height < data->ini.game.height
      && data->pos.x - 2 + data->actual.width < data->ini.game.width
      && check_collision(data->_tmp, data->ini.game.width,
			 data->ini.game.height) == 0)
    my_copy_tab(data->_tmp, data->tmp, data->ini.game.width,
		data->ini.game.height);
  else
    {
      if ((data->actual.form =
	   rotate_left(data->actual.form, &data->actual.width,
		       &data->actual.height)) == NULL)
	quit_game(data);
    }
  set_map(data->map, &data->pos, &data->actual, data->actual.color);
  return (0);
}

int	drop_tetri(t_loop *data)
{
  data->timer = 0;
  my_copy_tab(data->tmp, data->_tmp, data->ini.game.width,
	      data->ini.game.height);
  set_zero(data->_tmp, &data->pos, &data->actual);
  set_zero(data->map, &data->pos, &data->actual);
  data->pos.y = data->pos.y + 1;
  add_tab(data->_tmp, &data->actual, &data->pos);
  if (data->pos.y - 2 + data->actual.height < data->ini.game.height
      && check_collision(data->_tmp, data->ini.game.width,
			 data->ini.game.height) == 0)
    my_copy_tab(data->_tmp, data->tmp, data->ini.game.width,
		data->ini.game.height);
  else
    {
      data->pos.y = data->pos.y - 1;
      set_map(data->map, &data->pos, &data->actual, data->actual.color);
      return (1);
    }
  set_map(data->map, &data->pos, &data->actual, data->actual.color);
  return (0);
}
