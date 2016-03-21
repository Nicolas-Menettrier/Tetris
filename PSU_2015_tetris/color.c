/*
** color.c for color in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Fri Mar 18 21:55:40 2016 pinta_a
** Last update Sun Mar 20 23:50:01 2016 pinta_a
*/

#include "proto.h"

void	my_color(t_loop *loop)
{
  if (has_colors() == TRUE)
    start_color();
  else
    quit_game(loop);
}
