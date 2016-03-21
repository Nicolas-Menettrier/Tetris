/*
** max.c for max in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Fri Mar 18 12:18:17 2016 pinta_a
** Last update Sat Mar 19 00:01:46 2016 pinta_a
*/

#include "struct.h"
#include "proto.h"

int	max_dim(t_loop *loop, int opt)
{
  int	max;
  int	i;

  i = 0;
  max = 0;
  while (i < loop->nb_form)
    {
      if (loop->form[i].error == 0)
	{
	  if (opt == 1 && loop->form[i].width > max)
	    max = loop->form[i].width;
	  if (opt == 2 && loop->form[i].height > max)
	    max = loop->form[i].height;
	}
      i = i + 1;
    }
  return (max);
}

int	max_arg(t_init *ini)
{
  int	max;
  int	len;
  int	i;

  i = 2;
  max = my_strlen(ini->opt[1]);
  while (i < 7)
    {
      if ((len = my_strlen(ini->opt[i])) > max)
	max = len;
      i = i + 1;
    }
  return (max);
}
