/*
** EPITECH PROJECT, 2022
** tools_setenv.c
** File description:
** tools for setenv
*/

#include "minishell.h"

int reset_value_add_word(ms_t *ms, int check, int i)
{
    ms->env[i] = my_strcat(ms->cmd[1], "=");
    ms->env[check] = my_strcat(ms->cmd[1], "=");
    return (TRUE);
}

int reset_word_find(ms_t *ms, int check)
{
    ms->env[check] = my_strcat(ms->cmd[1], "=");
    return (TRUE);
}

int add_value_word_not_find(ms_t *ms, int check)
{
    ms->env[check] = my_strcat(ms->cmd[1], "=");
    if (ms->cmd[2] != NULL)
        ms->env[check] = my_strcat(ms->env[check], ms->cmd[2]);
    return (TRUE);
}

int add_value_word_find(ms_t *ms, int check, int i)
{
    ms->env[i] = my_strcat(ms->cmd[1], "=");
    if (ms->cmd[2] != NULL)
        ms->env[i] = my_strcat(ms->env[i], ms->cmd[2]);
    ms->env[check] = my_strcat(ms->cmd[1], "=");
    if (ms->cmd[2] != NULL)
        ms->env[check] = my_strcat(ms->env[check], ms->cmd[2]);
    return (TRUE);
}
