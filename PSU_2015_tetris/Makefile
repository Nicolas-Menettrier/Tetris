##
## Makefile for tetris in /home/pinta/rendu/TETRIS
## 
## Made by pinta_a
## Login   <pinta_a@epitech.net>
## 
## Started on  Wed Feb 24 10:58:27 2016 pinta_a
## Last update Sun Mar 20 23:26:04 2016 pinta_a
##

NAME	= tetris

SRC	= init_tetrimino.c	\
	  sort_tetrimino.c	\
	  get_next_line.c	\
	  get_tetrimino.c	\
	  init_struct.c		\
	  form_werror.c		\
	  select_move.c		\
	  my_put_nbr.c		\
	  print_line.c		\
	  init_other.c		\
	  move_tetri.c		\
	  check_line.c		\
	  init_level.c		\
	  init_form.c		\
	  init_main.c		\
	  init_pars.c		\
	  game_over.c		\
	  copy_form.c		\
	  my_strcmp.c		\
	  my_getnbr.c		\
	  set_zero.c		\
	  set_term.c		\
	  init_map.c		\
	  game_opt.c		\
	  copy_tab.c		\
	  getname.c		\
	  putchar.c		\
	  poirier.c		\
	  pommier.c		\
	  rotate.c		\
	  strlen.c		\
	  debug.c		\
	  error.c		\
	  color.c		\
	  view.c		\
	  help.c		\
	  term.c		\
	  main.c		\
	  max.c			\
	  ptr.c

CFLAGS	+= -W -Wall -Werror -ansi -pedantic

LIB	= -lncurses -Lmy_printf/lib -lmy

OBJ	= $(SRC:.c=.o)

RM	= rm -rf *~

CC	= gcc -g3

all:	 $(NAME)

$(NAME): $(OBJ)
	 make -C ./my_printf/
	 $(CC) $(OBJ) -o $(NAME) $(LIB)

clean:
	 make clean -C ./my_printf/
	 $(RM) $(OBJ)

fclean:	 clean
	 make fclean -C ./my_printf/
	 $(RM) $(NAME)

re:	 fclean all
	 make re -C ./my_printf/

.PHONY:	 all clean fclean re
