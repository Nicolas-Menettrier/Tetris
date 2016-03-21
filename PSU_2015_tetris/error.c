/*
** error.c for error in /home/menett_a/Modules/Unix/PSU_2015_tetris
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Sun Mar 20 18:39:36 2016 Nicolas Menettrier
** Last update Mon Mar 21 20:37:52 2016 Nicolas Menettrier
*/

#include "proto.h"

void	my_error(t_loop *data)
{
  int	i;

  i = 0;
  data->map_error = 0;
  if (data->ini.game.width >= COLS - 50 ||
      data->ini.game.height >= LINES - 5)
    data->map_error = 1;
  while (i < data->nb_form)
    {
      if (data->form[i].color < 0 || data->form[i].color > 8)
	data->form[i].color = 1;
      if (data->form[i].error != 1
	  && (data->form[i].width > data->ini.game.width
	      || data->form[i].height > data->ini.game.height))
	data->form[i].error = 1;
      i = i + 1;
    }
}
