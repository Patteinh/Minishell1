/*
** EPITECH PROJECT, 2022
** signal.c
** File description:
** signal gestion
*/

#include "minishell.h"

void ctrl_c()
{
    my_putstr("\n$>");
}

void segfault()
{
    my_putstr("Segmentation fault\n");
}

void my_signal(void)
{
    signal(SIGINT, ctrl_c);
    signal(SIGSEGV, segfault);
}
