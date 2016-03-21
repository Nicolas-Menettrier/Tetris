/*
** ptr.c for ptr in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Fri Mar 18 17:14:26 2016 pinta_a
** Last update Sat Mar 19 18:48:09 2016 pinta_a
*/

#include <curses.h>
#include "proto.h"

void	init_ptr(int (**ptr)(t_loop *data))
{
  ptr[0] = move_left;
  ptr[1] = move_right;
  ptr[2] = turn_tetri;
  ptr[3] = drop_tetri;
  ptr[4] = quit_game;
  ptr[5] = pause_game;
}
