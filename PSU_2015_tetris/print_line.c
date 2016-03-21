/*
** print_line.c for print_line in /home/pinta_a/rendu/TETRIS
**
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
**
** Started on  Tue Mar 15 17:47:34 2016 pinta_a
** Last update Wed Mar 16 19:02:38 2016 Nicolas Menettrier
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"
#include "proto.h"

#include <stdio.h>

void	print_line(int *line, int width)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < width)
    {
      if (line[i] == 1)
	j = i;
      i = i + 1;
    }
  i = 0;
  while (i <= j)
    {
      my_putchar(line[i] == 1 ? ('*') : (' '));
      i = i + 1;
    }
  my_putchar('\n');
}
