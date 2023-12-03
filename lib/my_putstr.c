/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** display strings
*/

#include "my.h"

void my_putstr(char const *str)
{
    for (; *str; str++)
        my_putchar(*str);
}
