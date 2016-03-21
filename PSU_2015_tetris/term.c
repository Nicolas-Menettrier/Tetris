/*
** term.c for term in /home/menett_a/Modules/Unix/PSU_2015_tetris
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Thu Mar 17 17:25:11 2016 Nicolas Menettrier
** Last update Thu Mar 17 19:24:18 2016 Nicolas Menettrier
*/

#include "proto.h"

char	*my_term(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strcmp_equal(env[i], "TERM=") == 1)
	return (&env[i][5]);
      i = i + 1;
    }
  return (NULL);
}
