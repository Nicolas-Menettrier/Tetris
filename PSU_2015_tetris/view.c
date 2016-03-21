/*
** view.c for view in /home/pinta_a/rendu/TETRIS/last/PSU_2015_tetris
**
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
**
** Started on  Sat Mar 19 12:45:41 2016 pinta_a
** Last update Sun Mar 20 22:30:52 2016 pinta_a
*/

#include "struct.h"
#include "proto.h"

void	init_pair_color(int i)
{
  init_pair(1 + i, 1, 0);
  init_pair(2 + i, 2, 0);
  init_pair(3 + i, 3, 0);
  init_pair(4 + i, 4, 0);
  init_pair(5 + i, 5, 0);
  init_pair(6 + i, 6, 0);
  init_pair(7 + i, 7, 0);
}

void	game_view(t_loop *data)
{
  int	i;
  int	j;

  i = 1;
  while (i < data->ini.game.height + 1)
    {
      j = 1;
      while (j < data->ini.game.width + 1)
	{
	  if (data->map[i][j] > 0)
	    {
	      init_pair_color(0);
	      wattron(data->win.game, COLOR_PAIR(data->map[i][j]));
	      mvwprintw(data->win.game, i, j, "*");
	      wattroff(data->win.game, COLOR_PAIR(data->map[i][j]));
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
}

void	stat_view(t_loop *data)
{
  mvwprintw(data->win.stat, 1, 1, "-High Score : 189030");
  mvwprintw(data->win.stat, 3, 1, "-Level : %d", data->ini.game.level);
  mvwprintw(data->win.stat, 5, 1, "-Line(s) : %d", data->ini.game.line);
  mvwprintw(data->win.stat, 6, 1, "-Score : %d", data->ini.game.score);
  init_pair_color(7);
  wattron(data->win.stat, COLOR_PAIR(1) | A_BOLD);
  mvwprintw(data->win.stat, 8, 1, "*** *** *** *** * ***");
  wattroff(data->win.stat, COLOR_PAIR(1));
  wattron(data->win.stat, COLOR_PAIR(2));
  mvwprintw(data->win.stat, 9, 1, " *  *    *  * *   *  ");
  wattroff(data->win.stat, COLOR_PAIR(2));
  wattron(data->win.stat, COLOR_PAIR(3));
  mvwprintw(data->win.stat, 10, 1, " *  ***  *  **  * ***");
  wattroff(data->win.stat, COLOR_PAIR(3));
  wattron(data->win.stat, COLOR_PAIR(4));
  mvwprintw(data->win.stat, 11, 1, " *  *    *  * * *   *");
  wattroff(data->win.stat, COLOR_PAIR(4));
  wattron(data->win.stat, COLOR_PAIR(5));
  mvwprintw(data->win.stat, 12, 1, " *  ***  *  * * * ***");
  wattroff(data->win.stat, COLOR_PAIR(5) | A_BOLD);
}

void	next_view(t_loop *data)
{
  int	i;
  int	j;

  i = 0;
  while (i < data->next.height)
    {
      j = 0;
      while (j < data->next.width)
	{
	  if (data->next.form[i][j] == 1)
	    {
	      init_pair_color(0);
	      wattron(data->win.next, COLOR_PAIR(data->next.color));
	      mvwprintw(data->win.next, i + 1, j + 1, "*");
	      wattroff(data->win.next, COLOR_PAIR(data->next.color));
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
}

int	my_view(t_loop *data)
{
  werase(data->win.game);
  werase(data->win.stat);
  werase(data->win.next);
  game_view(data);
  stat_view(data);
  next_view(data);
  if (wborder(data->win.stat, '|', '|', '-', '-', '+', '+', '+', '+') != OK
      || wborder(data->win.game, '|', '|', '-', '-', '0', '0', '0', '0') != OK
      || wborder(data->win.next, '|', '|', '-', '-', '0', '0', '0', '0') != OK)
    return (1);
  mvwprintw(data->win.next, 0, 1, "Next:");
  wrefresh(data->win.game);
  wrefresh(data->win.stat);
  wrefresh(data->win.next);
  return (0);
}
