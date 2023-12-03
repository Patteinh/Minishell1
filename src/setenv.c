/*
** EPITECH PROJECT, 2022
** setenv
** File description:
** setenv cmd
*/

#include "minishell.h"

int set_setenv(ms_t *ms)
{
    int i = 0;
    for (i = 0; ms->env[i]; i++);
    ms->env = realloc_env(ms->env, i);
    return (i);
}

int check_value_exist(ms_t *ms)
{
    int check = -1;

    for (int i = 0; ms->env[i]; i++)
        for (int j = 0; ms->env[i][j]; j++) {
            if (ms->env[i][j] != ms->cmd[1][j])
                break;
            if (ms->env[i][j] == ms->cmd[1][j] && ms->env[i][j + 1] == '=')
                check = i;
        }
    return (check);
}

char **realloc_env(char **env, int i)
{
    char **tmp = malloc(sizeof(char *) * (i + 2));
    int j = 0;

    for (int i = 0; env[i]; i++) {
        tmp[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        for (j = 0; env[i][j]; j++)
            tmp[i][j] = env[i][j];
        tmp[i][j] = '\0';
    }
    tmp[i + 1] = NULL;
    return (tmp);
}

int setenv_three(ms_t *ms)
{
    int i = set_setenv(ms);
    int check = check_value_exist(ms);

    if (check != WORD_EXIST)
        return (add_value_word_not_find(ms, check));
    return (add_value_word_find(ms, check, i));
}

int setenv_two(ms_t *ms)
{
    int i = set_setenv(ms);
    int check = check_value_exist(ms);

    if (check != WORD_EXIST)
        return (reset_word_find(ms, check));
    return (reset_value_add_word(ms, check, i));
}
