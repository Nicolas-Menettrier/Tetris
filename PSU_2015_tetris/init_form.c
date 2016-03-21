/*
** init_form.c for init_form in /home/pinta_a/rendu/TETRIS
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Mon Mar 14 19:59:56 2016 pinta_a
** Last update Sun Mar 20 23:47:47 2016 pinta_a
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"
#include "proto.h"

void		my_init(t_form *form)
{
  form->width = 0;
  form->height = 0;
  form->color = 0;
  form->error = 0;
}
