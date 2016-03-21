/*
** game_opt.c for game_opt in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Fri Mar 18 18:47:14 2016 pinta_a
** Last update Sat Mar 19 18:58:03 2016 pinta_a
*/

#include "proto.h"

int	quit_game(t_loop *data)
{
  my_set_term(data, 1);
  delwin(data->win.next);
  delwin(data->win.stat);
  delwin(data->win.game);
  endwin();
  exit(1);
  return (0);
}

int	pause_game(t_loop *data)
{
  data->pause = (data->pause + 1) % 2;
  return (0);
}
