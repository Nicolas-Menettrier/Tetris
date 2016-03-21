/*
** copy_form.c for copy_form in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Sat Mar 19 23:18:52 2016 pinta_a
** Last update Sun Mar 20 22:50:08 2016 pinta_a
*/

#include "proto.h"

void	copy_form_tab(t_form *form, t_form *new)
{
  int	i;
  int	j;

  i = 0;
  while (i < new->height)
    {
      j = 0;
      while (j < new->width)
	{
	  new->form[i][j] = form->form[i][j];
	  j = j + 1;
	}
      i = i + 1;
    }
}

void	my_copy_form(t_loop *data, t_form *form, t_form *new)
{
  int	i;

  i = 0;
  new->color = form->color;
  new->width = form->width;
  new->height = form->height;
  new->error = form->error;
  if ((new->form = malloc(sizeof(int *) * new->height)) == NULL)
    quit_game(data);
  while (i < new->height)
    {
      if ((new->form[i] = malloc(sizeof(int) * new->width)) == NULL)
	quit_game(data);
      i = i + 1;
    }
  copy_form_tab(form, new);
}
