/*
** my_put_nbr.c for minitalk in /home/pinta/rendu/PSU_2015_minitalk/client
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Mon Feb  1 19:38:08 2016 pinta_a
** Last update Tue Mar 15 17:55:55 2016 pinta_a
*/

#include <unistd.h>
#include "proto.h"
#define ABS(x) (x < 0 ? (-x) : (x))

void		my_recursive(int nb)
{
  if (nb != 0)
    {
      my_recursive(nb / 10);
      my_putchar(ABS(nb % 10) + 48);
    }
}

void		my_put_nbr(int nb)
{
  if (nb < 0)
    my_putchar('-');
  if (nb == 0)
    my_putchar('0');
  else
    my_recursive(nb);
}
