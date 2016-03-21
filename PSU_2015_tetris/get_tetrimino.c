/*
** get_tetrimino.c for get_tetrimino in /home/pinta_a/rendu/TETRIS
**
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
**
** Started on  Thu Mar 10 23:00:09 2016 pinta_a
** Last update Sun Mar 20 20:43:03 2016 Nicolas Menettrier
*/

#include "proto.h"

int	get_form_line(t_form *form, char *str, int i)
{
  int	j;

  j = 0;
  while (str[j] != '\0' && j < form->width)
    {
      form->form[i][j] = (str[j] == '*' ? (1) : (0));
      j = j + 1;
    }
  while (j < form->width)
    {
      form->form[i][j] = 0;
      j = j + 1;
    }
  j = 0;
  while (str[j] != '\0')
    {
      if (str[j] != '*' && str[j] != ' ')
	return (1);
      if (str[j] != ' ' && j >= form->width)
	  return (1);
      j = j + 1;
    }
  return (0);
}

int	my_get_form_tetrimino(t_form *form, int fd)
{
  char	*str;
  int	i;

  i = 0;
  while (i < form->height)
    {
      if ((str = get_next_line(fd)) == NULL)
	return (1);
      if (get_form_line(form, str, i))
	return (2);
      free(str);
      i = i + 1;
    }
  return (0);
}

int	my_get_info_tetrimino(t_form *form, int fd)
{
  char	*str;
  int	i;

  i = 0;
  if ((str = get_next_line(fd)) == NULL)
    return (1);
  if (my_getnbr(str, &form->width, &i))
    return (2);
  i = i + 1;
  if (my_getnbr(str, &form->height, &i))
    return (3);
  i = i + 1;
  if (my_getnbr(str, &form->color, &i))
    return (4);
  if (str[i] != '\0')
    return (5);
  free(str);
  return (0);
}
