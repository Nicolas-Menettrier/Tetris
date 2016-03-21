/*
** putchar.c for putchar in /home/pinta_a/rendu/TETRIS/PSU_2015_tetris
**
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
**
** Started on  Wed Mar 16 18:28:45 2016 pinta_a
** Last update Sat Mar 19 18:56:48 2016 menett_a
*/

#include <unistd.h>

int	my_putcherr(int c)
{
  write(2, &c, 1);
  return (0);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  while (*str != '\0')
    my_putchar(*str++);
}

int	my_putsterr(char *str)
{
  while (*str != '\0')
    my_putcherr(*str++);
  return (-1);
}

void	my_putstr_space(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	my_putstr("(space)");
      else if (str[i] == 27)
	my_putstr("^E");
      else
	my_putchar(str[i]);
      i = i + 1;
    }
}
