/*
** set_term.c for set_term in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Fri Mar 18 14:39:18 2016 pinta_a
** Last update Fri Mar 18 15:45:38 2016 pinta_a
*/

#include <sys/ioctl.h>
#include <termios.h>
#include <curses.h>
#include <term.h>
#include "struct.h"

int	my_set_term(t_loop *loop, int mode)
{
  if (mode == 0)
    {
      if (ioctl(0, TCGETS, &loop->old) == -1
	  || ioctl(0, TCGETS, &loop->new) == -1)
	return (-1);
      loop->new.c_lflag = loop->new.c_lflag & ~ECHO;
      loop->new.c_lflag = loop->new.c_lflag & ~ICANON;
      loop->new.c_cc[VMIN] = 0;
      loop->new.c_cc[VTIME] = 1;
      if (ioctl(0, TCSETS, &loop->new) == -1)
	return (-1);
    }
  if (mode == 1 && ioctl(0, TCSETS, &loop->old) == -1)
    return (-1);
  return (0);
}
