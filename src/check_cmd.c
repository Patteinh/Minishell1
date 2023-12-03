/*
** EPITECH PROJECT, 2022
** cmd
** File description:
** commands
*/

#include "minishell.h"

int my_cd(ms_t *ms)
{
    cd_t *cd = malloc(sizeof(cd_t));
    set_cd(ms, cd);

    if ((cd->lcmd == 1) || (cd->lcmd == 2 && !my_strcmp(ms->cmd[1], "~")))
        return (go_home(ms, cd));
    if (cd->lcmd == 2 && !my_strcmp(ms->cmd[1], "-"))
        return (go_last_path(ms, cd));
    if (!my_strcmp(ms->cmd[1], "..") || !my_strcmp(ms->cmd[1], "../"))
        return (go_back(ms, cd));
    free(cd->pwd);
    return (go_path(ms->cmd[1]));
}

int my_unsetenv(ms_t *ms)
{
    if (ms->len_cmd == 2)
        return (unset(ms));
    return (FALSE);
}

int my_setenv(ms_t *ms)
{
    if (ms->len_cmd == 1)
        return (my_env(ms));
    if (ms->len_cmd == 2)
        return (setenv_two(ms));
    if (ms->len_cmd == 3)
        return (setenv_three(ms));
    return (FALSE);
}

int my_env(ms_t *ms)
{
    for (int i = 0; ms->env[i]; i++)
        my_printf("%s\n", ms->env[i]);
    return (TRUE);
}

int my_exit(ms_t *ms)
{
    free_all(ms);
    my_putstr("exit\n");
    exit(TRUE);
}
