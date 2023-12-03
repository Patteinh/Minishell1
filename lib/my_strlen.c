/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** count char in string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int size = 0;

    for (; str[size]; size++);
    return (size);
}
