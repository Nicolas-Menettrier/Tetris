/*
** init_struct.c for init_struct in /Users/menett_a/Modules/CprogElem/CPE_2015_tetris
**
** Made by menett_a
** Login   <menett_a@epitech.eu>
**
** Started on  Sat Feb 27 13:03:37 2016 menett_a
** Last update Fri Mar 18 17:40:14 2016 pinta_a
*/

#include "proto.h"

void	init_game(t_init *ini)
{
  ini->game.width = 10;
  ini->game.height = 20;
  ini->game.score = 0;
  ini->game.level = 1;
  ini->game.next = 1;
}

void	init_key(t_init *ini)
{
  if ((ini->opt[1] = tigetstr("kcub1")) == (char *)(-1))
    exit(1);
  if ((ini->opt[2] = tigetstr("kcuf1")) == (char *)(-1))
    exit(1);
  if ((ini->opt[3] = tigetstr("kcuu1")) == (char *)(-1))
    exit(1);
  if ((ini->opt[4] = tigetstr("kcud1")) == (char *)(-1))
    exit(1);
  ini->opt[5] = "q";
  ini->opt[6] = " ";
}

void	init_opt_two(t_init *ini)
{
  ini->opt_two[0] = "--level={num}";
  ini->opt_two[1] = "--key-left={K}";
  ini->opt_two[2] = "--key-right={K}";
  ini->opt_two[3] = "--key-turn={K}";
  ini->opt_two[4] = "--key-drop={K}";
  ini->opt_two[5] = "--key-quit={K}";
  ini->opt_two[6] = "--key-pause={K}";
  ini->opt_two[7] = "--map-size={row,col}";
}

void	init_opt_one(t_init *ini)
{
  ini->opt_one[0] = "-l";
  ini->opt_one[1] = "-kl";
  ini->opt_one[2] = "-kr";
  ini->opt_one[3] = "-kt";
  ini->opt_one[4] = "-kd";
  ini->opt_one[5] = "-kq";
  ini->opt_one[6] = "-kp";
  ini->opt_one[7] = NULL;
}
