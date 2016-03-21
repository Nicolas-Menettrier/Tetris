/*
** my_getnbr.c for my_getnbr in /Users/menett_a/Modules/CprogElem/CPE_2015_tetris
**
** Made by menett_a
** Login   <menett_a@epitech.eu>
**
** Started on  Mon Mar 14 20:29:12 2016 menett_a
** Last update Sat Mar 19 17:04:44 2016 pinta_a
*/

#include "proto.h"

int	my_getnbr_x(char *str, int x, int *i)
{
  int	nb;

  nb = 0;
  while (str[*i] != '\0')
    {
      if (str[*i] >= '0' && str[*i] <= '9')
	nb = nb * 10 + str[*i] - 48;
      else if (str[*i] == ',' && x == 1)
	{
	  *i = *i + 1;
	  return (nb);
	}
      else
	return (-1);
      *i = *i + 1;
    }
  return (nb);
}

int	my_getnbr_a(char *str, int *nb)
{
  int	j;

  j = 0;
  *nb = 0;
  while (str[j] >= '0' && str[j] <= '9')
    {
      *nb = *nb * 10 + (str[j] - 48);
      j = j + 1;
    }
  if (str[j] != '\0')
    return (1);
  return (0);
}
int	my_getnbr(char *str, int *nb, int *i)
{
  int	j;

  j = *i;
  while (str[j] >= '0' && str[j] <= '9')
    {
      *nb = *nb * 10 + (str[j] - 48);
      j = j + 1;
    }
  if ((str[j] != ' ' && str[j] != '\0') || j == *i)
    return (1);
  *i = j;
  return (0);
}
