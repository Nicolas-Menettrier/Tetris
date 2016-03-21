/*
** getname.c for getname in /home/pinta_a/rendu/TETRIS
**
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
**
** Started on  Tue Mar 15 17:12:39 2016 pinta_a
** Last update Sun Mar 20 12:42:55 2016 Nicolas Menettrier
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"
#include "proto.h"

char		*my_getname(char *str)
{
  char		*name;
  int		i;
  int		j;

  i = my_strlen(str) - 10;
  j = 0;
  if ((name = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  while (j < i)
    {
      name[j] = str[j];
      j = j + 1;
    }
  name[j] = '\0';
  return (name);
}
