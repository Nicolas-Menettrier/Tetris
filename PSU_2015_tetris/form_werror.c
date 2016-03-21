/*
** form_werror.c for form_werror in /home/pinta_a/rendu/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Sun Mar 20 17:53:20 2016 pinta_a
** Last update Sun Mar 20 17:55:31 2016 pinta_a
*/

#include "proto.h"

int	nb_form_werror(t_loop *data)
{
  int	nb;
  int	i;

  i = 0;
  nb = 0;
  while (i < data->nb_form)
    {
      if (data->form[i].error == 0)
	nb = nb + 1;
      i = i + 1;
    }
  return (nb);
}
