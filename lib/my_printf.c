/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_printf
*/

#include "my.h"

void my_flags(char *str, va_list args, int i)
{
    switch (str[i]) {
        case 'c' :
            my_putchar(va_arg(args, int));
            break;
        case 'd' :
            my_put_nbr(va_arg(args, int));
            break;
        case 's' :
            my_putstr(va_arg(args, const char *));
            break;
        case 'e' :
            my_perror(va_arg(args, const char *));
            break;
    }
}

int my_putspace(char *str, int i)
{
    int stock = i;

    for (;str[i] == ' '; i++);
    if (stock < i)
        my_putchar(' ');
    return (i);
}

void my_printf(char *str, ...)
{
    va_list args;
    va_start(args, str);
    int i = 0;

    while (str[i]) {
        if (str[i] == '%') {
            i++;
            i = my_putspace(str, i);
            my_flags(str, args, i);
        } else
            my_putchar(str[i]);
        i++;
    }
    va_end(args);
}
