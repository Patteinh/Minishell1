/*
** EPITECH PROJECT, 2022
** unsetenv.c
** File description:
** unset env
*/

#include "minishell.h"

int unset(ms_t *ms)
{
    int j = 0;
    int i = check_value_exist(ms);
    char **tmp4 = ms->env;

    if (i == ms->size_env)
        return (TRUE);
    ms->env = malloc(sizeof(char *) * (ms->size_env + 1));
    ms->size_env--;
    for (; tmp4[j] && j < i; j++)
        ms->env[j] = my_strdup(tmp4[j]);
    for (; tmp4[j + 1]; j++)
        ms->env[j] = my_strdup(tmp4[j + 1]);
    ms->env[j] = NULL;
    return (TRUE);
}
