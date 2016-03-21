/*
** poirier.c for poirier in /home/pinta_a/rendu/poton/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Sun Mar 20 23:24:51 2016 pinta_a
** Last update Sun Mar 20 23:45:53 2016 pinta_a
*/

#include "proto.h"

int	poirier_main(t_loop *data, int size)
{
  if ((size = read(0, data->buff, data->ini.max)) < 0)
    quit_game(data);
  data->buff[size] = '\0';
  if (data->pause == 0)
    data->timer = data->timer + 2 *
      (data->ini.game.level > 13 ? (13) : (data->ini.game.level));
  if (size > 0)
    {
      if (check_move(data->buff, data, data->ptr))
	init_new_form(data, 1);
      if (my_view(data))
	quit_game(data);
    }
  return (0);
}

int	init_main_loop(t_loop *data)
{
  if (data->map_error == 1)
    {
      my_putsterr("Resize your terminal!\n");
      quit_game(data);
    }
  if (nb_form_werror(data) == 0)
    return (1);
  if (init_first_tetri(data))
    return (1);
  if ((data->buff = malloc(sizeof(char) * (data->ini.max + 1))) == NULL)
    return (my_putsterr("Malloc failed\n"));
  if (my_set_term(data, 0) == -1)
    return (1);
  return (0);
}
