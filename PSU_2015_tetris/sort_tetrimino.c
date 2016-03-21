/*
** sort_tetrimino.c for sort_tetrimino in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Thu Mar 17 15:10:06 2016 pinta_a
** Last update Thu Mar 17 17:14:02 2016 pinta_a
*/

#include "struct.h"
#include "proto.h"

void		my_swap_tetrimino(t_form *form1, t_form *form2)
{
  t_form	swap;

  swap = *form1;
  *form1 = *form2;
  *form2 = swap;
}

int	my_compare_str(char *str, char *stv)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && stv[i] != '\0' && str[i] == stv[i])
    i = i + 1;
  if (str[i] > stv[i])
    return (1);
  if (str[i] < stv[i])
    return (-1);
  return (0);
}

void	sort_tetrimino(t_loop *loop)
{
  int	i;

  i = 0;
  while (i < loop->nb_form - 1)
    {
      if (my_compare_str(loop->form[i].name, loop->form[i + 1].name) == 1)
	{
	  my_swap_tetrimino(&loop->form[i], &loop->form[i + 1]);
	  i = -1;
	}
      i = i + 1;
    }
}
