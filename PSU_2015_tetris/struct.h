/*
** struct.h for tetris in /home/pinta/rendu/TETRIS/PSU_2015_my_ls
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Tue Feb 23 21:19:10 2016 pinta_a
** Last update Sun Mar 20 23:31:47 2016 pinta_a
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include <curses.h>
# include <termios.h>

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

typedef struct		s_game
{
  unsigned int		score;
  unsigned int		line;
  int			width;
  int			height;
  int			level;
  int			next;
}			t_game;

typedef struct		s_win
{
  WINDOW		*stat;
  WINDOW		*game;
  WINDOW		*next;
}			t_win;

typedef struct		s_init
{
  char			*opt_one[8];
  char			*opt_two[8];
  char			*opt[7];
  int			max;
  t_game		game;
}			t_init;

typedef struct		s_form
{
  int			**form;
  char			*name;
  int			width;
  int			height;
  int			color;
  int			error;
}			t_form;

typedef struct		s_loop
{
  struct s_form		*form;
  struct s_init		ini;
  struct s_win		win;
  struct termios	old;
  struct termios	new;
  struct s_form		actual;
  struct s_form		next;
  struct s_pos		pos;
  int			(*ptr[6])(struct s_loop *);
  int			**_tmp;
  int			**tmp;
  int			**map;
  int			nb_form;
  int			map_error;
  int			pause;
  int			debug;
  int			timer;
  char			*buff;
}			t_loop;

#endif /* !STRUCT_H_ */
