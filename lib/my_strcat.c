/*
** EPITECH PROJECT, 2022
** strcat
** File description:
** strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest) + my_strlen(src);
    char *tmp = malloc(sizeof(char) * (len + 1));
    int i = 0;
    int j = 0;

    for (; dest[i]; i++)
        tmp[i] = dest[i];
    for (; src[j]; i++, j++)
        tmp[i] = src[j];
    tmp[i] = '\0';
    return (tmp);
}
