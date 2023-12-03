/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** malloc copy string
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    dest = my_strcpy(dest, src);
    return (dest);
}
