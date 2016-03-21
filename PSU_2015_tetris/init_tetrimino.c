/*
** init_tetrimino.c for tetris in /home/pinta_a/rendu/PSU_2015_tetris
**
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
**
** Started on  Tue Mar 15 22:03:54 2016 pinta_a
** Last update Sun Mar 20 20:41:49 2016 Nicolas Menettrier
*/

#include "proto.h"

int		get_nb_form()
{
  struct dirent	*file;
  DIR		*dir;
  int		nb;

  nb = 0;
  if ((dir = opendir("tetriminos")) == NULL)
    {
      write(2, "can't find 'tetriminos' directory\n", 34);
      return (0);
    }
  while ((file = readdir(dir)) != NULL)
    {
      if (my_strcmp(file->d_name, ".") == 0
	  && my_strcmp(file->d_name, "..") == 0
	  && my_strncmp_end(file->d_name, ".tetrimino", 10))
	nb = nb + 1;
    }
  if (closedir(dir) == -1)
    return (0);
  return (nb);
}

int		my_malloc_form(t_form *form)
{
  int		i;

  i = 0;
  if ((form->form = malloc(sizeof(int *) * (form->height))) == NULL)
    return (1);
  while (i < form->height)
    {
      if ((form->form[i] = malloc(sizeof(int) * (form->width))) == NULL)
	return (2);
      i = i + 1;
    }
  return (0);
}

int		my_init_form(char *name, t_form *form, char *d_name)
{
  int		fd;

  if ((fd = open(name, 'r')) == -1)
    return (1);
  if ((form->name = my_getname(d_name)) == NULL)
    return (2);
  if (my_get_info_tetrimino(form, fd))
    return (3);
  if (my_malloc_form(form))
    return (4);
  if (my_get_form_tetrimino(form, fd))
    return (5);
  if (close(fd) == -1)
    return (6);
  return (0);
}

int		my_load_tetriminos(struct dirent *file, t_form *form, int *i)
{
  char		*name;

  name = my_realloc("tetriminos/", file->d_name, 11, my_strlen(file->d_name));
  if (name == NULL)
    return (1);
  my_init(form);
  if (my_init_form(name, form, file->d_name))
    form->error = 1;
  *i = *i + 1;
  return (0);
}

int		init_tetriminos(t_loop *loop)
{
  struct dirent	*file;
  DIR		*dir;
  int		i;

  i = 0;
  if ((loop->nb_form = get_nb_form()) == 0)
    return (1);
  if ((loop->form = malloc(sizeof(t_form) * loop->nb_form)) == NULL)
    return (2);
  if ((dir = opendir("tetriminos")) == NULL)
    {
      write(2, "can't find 'tetriminos' directory\n", 34);
      return (3);
    }
  while ((file = readdir(dir)) != NULL)
    {
      if (my_strncmp_end(file->d_name, ".tetrimino", 10)
	  && my_load_tetriminos(file, &loop->form[i], &i))
	return (4);
    }
  if (closedir(dir) == -1)
    return (5);
  return (0);
}
