/*
** EPITECH PROJECT, 2022
** tools_cd.c
** File description:
** tools for cd
*/

#include "minishell.h"

int len_home(ms_t *ms)
{
    int len = 0;

    for (int i = 0; ms->env[i]; i++)
        if (!my_strncmp(ms->env[i], "HOME=", 5))
            len = my_strlen(ms->env[i]) - 5;
    return (len);
}

char *path_home(ms_t *ms, char *home, int ihome)
{
    int k = 0;

    for (int j = 5; ms->env[ihome][j]; j++, k++)
        home[k] = ms->env[ihome][j];
    home[k] = '\0';
    return (home);
}

int find_var(ms_t *ms, const char *tmp)
{
    for (int i = 0; ms->env[i]; i++)
        if (!my_strncmp(ms->env[i], tmp, my_strlen(tmp)))
            return (i);
    return (0);
}

int len_var(ms_t *ms, const char *tmp)
{
    for (int i = 0; ms->env[i]; i++)
        if (!my_strncmp(ms->env[i], tmp, my_strlen(tmp)))
            return (my_strlen(ms->env[i]));
    return (0);
}

void change_oldpwd(ms_t *ms, cd_t *cd)
{
    char *tmp = NULL;
    char *path = malloc(sizeof(char) * (cd->lpwd + 1));
    path[cd->lpwd] = '\0';
    getcwd(path, cd->lpwd);
    tmp = my_strdup(ms->env[cd->iopwd]);
    ms->env[cd->iopwd] = my_strcat("OLDPWD=", path);
    free(tmp);
}
