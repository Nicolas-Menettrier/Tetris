/*
** my_strcmp.c for my_strcmp in /home/menett_a/rendu/Piscine_C_J06/ex_06
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Mon Oct  5 18:28:47 2015 Nicolas Menettrier
** Last update Wed Mar 16 18:37:12 2016 pinta_a
*/

#include "proto.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    i = i + 1;
  if (s1[i] == '\0' && s2[i] == '\0')
    return (1);
  return (0);
}

int	my_strcmp_equal(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '=' &&
	 s2[i] != '\0' && s1[i] != '=')
    i = i + 1;
  if (s1[i] == '=' && s2[i] == '=')
    return (1);
  return (0);
}

int		my_strncmp_end(char *str, char *stv, int n)
{
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  k = 0;
  while (str[i] != '\0')
    i = i + 1;
  while (stv[j] != '\0')
    j = j + 1;
  while (str[i] == stv[j] && i >= 0 && j >= 0 && k < n)
    {
      i = i - 1;
      j = j - 1;
      k = k + 1;
    }
  if (str[i] == stv[j])
    return (1);
  return (0);
}
