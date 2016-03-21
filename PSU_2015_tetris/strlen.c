/*
** strlen.c for strlen in /home/pinta_a/rendu/TETRIS/PSU_2015_tetris
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Wed Mar 16 18:34:01 2016 pinta_a
** Last update Wed Mar 16 18:34:38 2016 pinta_a
*/

#include "proto.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
