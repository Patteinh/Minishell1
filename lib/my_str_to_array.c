/*
** EPITECH PROJECT, 2022
** my_str_to_array.c
** File description:
** str to array with delim
*/

#include "my.h"

int no_delim(char c, char *d)
{
    for (int i = 0; d[i]; i++)
        if (c == d[i])
            return (1);
    return (0);
}

int its_delim(char *str, int i, char *d)
{
    if (no_delim(str[i], d)) {
        for (; no_delim(str[i], d); i++);
        i--;
    }
    return (i);
}

int count_word(char *str, char *d)
{
    int w = 1;

    for (int i = 0; str[i]; i++, w++)
        i = its_delim(str, i, d);
    return (w);
}

int len_w(char *str, int i, char *d)
{
    int len = 0;

    for (; !no_delim(str[i], d) && str[i]; len++, i++);
    return (len);
}

char **my_str_to_array(char *str, char *d)
{
    char **array = malloc(sizeof(char *) * (count_word(str, d) + 1));
    int i = 0;
    int line = 0;

    for (int c = 0; str[i]; c = 0, line++) {
        for (; no_delim(str[i], d) && str[i]; i++);
        array[line] = malloc(sizeof(char) * (len_w(str, i, d) + 1));
        for (; !no_delim(str[i], d) && str[i]; i++ , c++)
            array[line][c] = str[i];
        array[line][c] = '\0';
        for (; no_delim(str[i], d) && str[i]; i++);
    }
    array[line] = NULL;
    return (array);
}
