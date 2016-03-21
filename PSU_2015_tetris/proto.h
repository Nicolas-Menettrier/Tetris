/*
** proto.h for tetris in /home/pinta/rendu/TETRIS
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Wed Feb 24 11:57:27 2016 pinta_a
** Last update Sun Mar 20 23:44:17 2016 pinta_a
*/

#ifndef PROTO_H_
# define PROTO_H_

# include <curses.h>
# include <term.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <ncurses.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include "struct.h"

/*
** poirier.c
*/

int	init_main_loop(t_loop *loop);
int	poirier_main(t_loop *data, int size);

/*
** form_werror.c
*/

int	nb_form_werror(t_loop *data);

/*
** copy_form.c
*/

void	copy_form_tab(t_form *form, t_form *new);
void	my_copy_form(t_loop *data, t_form *form, t_form *new);

/*
** debug.c
*/

void	my_debug_form(t_loop *loop);
void	my_debug_keys(t_loop *loop);
void	my_debug(t_loop *loop);

/*
** copy_tab.c
*/

void	my_copy_tab(int **map, int **tmp, int width, int height);

/*
** check_line.c
*/

void	copy_line(int *dest, int *src, int size);
void	down_tab(t_loop *data, int i);
void	check_line(t_loop *data);

/*
** view.c
*/

void	game_view(t_loop *data);
void	stat_view(t_loop *data);
void	next_view(t_loop *data);
int	my_view(t_loop *data);

/*
** ptr.c
*/

void	init_ptr(int (**ptr)(t_loop *data));

/*
** rotate.c
*/

void	my_swap(int *a, int *b);
void	my_free(int **map, int height);
int	**my_malloc(int width, int height);
int	**rotate_right(int **form, int *width, int *height);
int	**rotate_left(int **form, int *width, int *height);

/*
** game_opt.c
*/

int	quit_game(t_loop *loop);
int	pause_game(t_loop *data);

/*
** pommier.c
*/

int	init_first_tetri(t_loop *data);
int	init_new_form(t_loop *data, int opt);
char	*init_window(t_loop *data);
void	init_pos(t_loop *data);
int	main_loop(t_loop *data);

/*
** max.c
*/

int	max_dim(t_loop *loop, int opt);
int	max_arg(t_init *ini);

/*
** set_term.c
*/

int	my_set_term(t_loop *loop, int mode);

/*
** my_getnbr.c
*/

int	my_getnbr(char *str, int *nb, int *i);
int	my_getnbr_x(char *str, int x, int *i);
int	my_getnbr_a(char *str, int *nb);

/*
** sort_tetrimino.c
*/

int	my_compare_str(char *str, char *stv);
void	my_swap_tetrimino(t_form *form1, t_form *form2);
void	sort_tetrimino(t_loop *loop);

/*
** getname.c
*/

char	*my_getname(char *str);

/*
** init_other.c
*/

int	init_other(char **argv, char *one, char *two);

/*
** putchar.c
*/

int	my_putcherr(int c);
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_putstr_space(char *str);
int	my_putsterr(char *str);

/*
** my_printf.c
*/

int	my_printf(char *str, ...);

/*
** help.c
*/

int	my_help(char *str);

/*
** strlen.c
*/

int	my_strlen(char *str);

/*
** my_put_nbr.c
*/

void	my_recursive(int nb);
void	my_put_nbr(int nb);

/*
** print_line.c
*/

void	print_line(int *line, int width);

/*
** game_over.c
*/

int	game_over(t_loop *data);

/*
** init_map.c
*/

void	fill_tmp(int **map, int height, int width);
int	**malloc_map(int height, int width);

/*
** init_tetrimino.c
*/

int	my_malloc_form(t_form *form);
int	my_init_form(char *name, t_form *form, char *d_name);
int	_my_load_tetriminos(struct dirent *file, t_form *form, int *i);
int	init_tetriminos(t_loop *loop);

/*
** get_tetrimino.c
*/

int	get_form_line(t_form *form, char *str, int i);
int	my_get_info_tetrimino(t_form *form, int fd);
int	my_get_form_tetrimino(t_form *form, int fd);

/*
** init_form.c
*/

void	my_init(t_form *form);

/*
** strcmp.c
*/

int	my_strncmp_end(char *str, char *stv, int n);

/*
** get_next_line.c
*/

char	*get_next_line(const int fd);
char	*my_getbefore(char *save, int save_size);
char	*my_getafter(char *save, int *save_size);
char	*my_realloc(char *str, char *buff, int str_size, int buff_size);
int	my_buff_next(char *buff, int size);
void	init_opt_one(t_init *);
void	init_opt_two(t_init *);
void	init_game(t_init *);
void	init_key(t_init *);
char	*opt_key(char *);
int	init_pars(t_loop *, char **, int);
int	init_main(t_loop *, char **, int);
int	my_getnbr_x(char *, int, int *);
int	my_strcmp_equal(char *, char *);
int	my_strcmp(char *, char *);

/*
** term.c
*/

char	*my_term(char **env);

/*
** main.c
*/

int	init_term(char **env, t_loop *loop, int argc, char **argv);

/*
** select_move.c
*/

int	check_move(char *cmd, t_loop *data, int (**ptr)(t_loop *));

/*
** move_tetri.c
*/

int	move_left(t_loop *data);
int	move_right(t_loop *data);
int	turn_tetri(t_loop *data);
int	drop_tetri(t_loop *data);

/*
** color.c
*/

void	my_color(t_loop *loop);

/*
** set_zero.c
*/

void	set_map(int **map, t_pos *pos, t_form *form, int color);
void	set_zero(int **map, t_pos *pos, t_form *form);
int	check_collision(int **map, int width, int height);
void	add_tab(int **map, t_form *form, t_pos *pos);

/*
** init_level.c
*/

void	init_level(t_init *ini, char **argv);

/*
** error.c
*/

void	my_error(t_loop *data);

#endif /* !PROTO_H_ */
