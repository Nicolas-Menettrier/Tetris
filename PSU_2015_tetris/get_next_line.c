
/*
** get_next_line.c for getnextline in /home/pinta/rendu/CPE_2015_getnextline
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Mon Jan 11 16:08:42 2016 pinta_a
** Last update Thu Mar 10 22:12:33 2016 pinta_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "proto.h"

char		*my_realloc(char *str, char *buff, int str_size, int buff_size)
{
  char		*new;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((new = malloc(sizeof(char) * (str_size + buff_size + 1))) == NULL)
    return (NULL);
  while (i < str_size)
    {
      new[i] = str[i];
      i = i + 1;
    }
  while (j < buff_size)
    {
      new[i] = buff[j];
      i = i + 1;
      j = j + 1;
    }
  new[i] = '\0';
  return (new);
}

char		*my_getbefore(char *save, int save_size)
{
  char		*str;
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < save_size && save[i] != '\n')
    i = i + 1;
  if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  while (j < i)
    {
      str[j] = save[j];
      j = j + 1;
    }
  str[j] = '\0';
  return (str);
}

char		*my_getafter(char *save, int *save_size)
{
  char		*str;
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < *save_size && save[i] != '\n')
    i = i + 1;
  str = &save[i + 1];
  while (str[j] != '\0')
    j = j + 1;
  *save_size = j;
  return (str);
}

int		my_buff_next(char *buff, int size)
{
  int		i;

  i = 0;
  while (i < size)
    {
      if (buff[i] == '\n')
	return (i);
      i = i + 1;
    }
  return (i);
}

char		*get_next_line(const int fd)
{
  static char	*save;
  static int	save_size;
  t_gnl		gnl;

  if (save == NULL)
    save = "\0";
  while (my_buff_next(save, save_size) == save_size
	 && (gnl.size = read(fd, gnl.buff, READ_SIZE)) > 0
	 && my_buff_next(gnl.buff, gnl.size) == gnl.size)
    {
      if ((save = my_realloc(save, gnl.buff, save_size, gnl.size)) == NULL)
	return (NULL);
      save_size = save_size + gnl.size;
    }
  if ((save = my_realloc(save, gnl.buff, save_size, gnl.size)) == NULL)
    return (NULL);
  if (gnl.size <= 0 && save_size <= 0)
    return (NULL);
  save_size = save_size + gnl.size;
  if ((gnl.str = my_getbefore(save, save_size)) == NULL)
    return (NULL);
  save = my_getafter(save, &save_size);
  return (gnl.str);
}
