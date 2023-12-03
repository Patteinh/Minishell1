/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** lib.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef _MY_H
    #define _MY_H

void my_putchar(char c);
void my_putstr(char const *str);
void my_perror(char const *str);
int  my_strlen(char const *str);
int  my_lenarray(char **array);
int  my_ischar(char c);
int  my_isnum(char **array);
int  my_put_nbr(int nb);
int  my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strcat(char *dest, char const *src);
int  my_strcmp(char const *s1, char const *s2);
int  my_strncmp(char const *s1, char const *s2, int n);
void my_printf(char *str, ...);
char **my_str_to_array(char *str, char *d);
void my_parray(char **array);
void my_free_array(char **array);

#endif
