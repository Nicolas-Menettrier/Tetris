/*
** debug.c for debug in /home/pinta_a/rendu/TETRIS
**
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
**
** Started on  Tue Mar 15 18:14:53 2016 pinta_a
** Last update Sat Mar 19 18:56:58 2016 menett_a
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"
#include "proto.h"

void	print_debug(char *str)
{
  my_putstr_space(str);
  my_putstr("\n");
}

void	my_debug_keys(t_loop *loop)
{
  my_printf("Key Left : ");
  print_debug(loop->ini.opt[1]);
  my_printf("Key Right : ");
  print_debug(loop->ini.opt[2]);
  my_printf("Key Turn : ");
  print_debug(loop->ini.opt[3]);
  my_printf("Key Drop : ");
  print_debug(loop->ini.opt[4]);
  my_printf("Key Quit : ");
  print_debug(loop->ini.opt[5]);
  my_printf("Key Pause : ");
  print_debug(loop->ini.opt[6]);
  my_printf("Next : ");
  my_putstr((loop->ini.game.next == 1 ? ("Yes\n") : ("No\n")));
  my_printf("Level : %d\n", loop->ini.game.level);
  my_printf("Size : %d*%d\n", loop->ini.game.height, loop->ini.game.width);
}

void	my_debug_form(t_loop *loop)
{
  int	i;
  int	j;

  i = 0;
  my_printf("Tetriminos : %d\n", loop->nb_form);
  while (i < loop->nb_form)
    {
      my_printf("Tetriminos : Name %s : ", loop->form[i].name);
      if (loop->form[i].error == 1)
	my_putstr("Error\n");
      else
	{
	  j = 0;
	  my_printf("Size %d*%d : ", loop->form[i].width, loop->form[i].height);
	  my_printf("Color %d :\n", loop->form[i].color);
	  while (j < loop->form[i].height)
	    {
	      print_line(loop->form[i].form[j], loop->form[i].width);
	      j = j + 1;
	    }
	}
      i = i + 1;
    }
}

void	my_debug(t_loop *loop)
{
  my_putstr("*** DEBUG MODE ***\n");
  my_debug_keys(loop);
  my_debug_form(loop);
  my_putstr("Press a key to start Tetris\n");
}
