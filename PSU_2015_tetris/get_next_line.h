/*
** get_next_line.h for getnextline in /home/pinta/rendu/CPE_2015_getnextline
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Mon Jan 11 17:03:15 2016 pinta_a
** Last update Thu Feb 25 19:38:37 2016 arnaud pinta
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (1)
# endif /* !READ_SIZE */

char	*get_next_line(const int fd);

typedef struct	s_gnl
{
  char		*str;
  char		buff[READ_SIZE];
  int		size;
}		t_gnl;

#endif /* !GETNEXTLINE_H_ */
