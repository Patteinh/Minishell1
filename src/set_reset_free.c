/*
** EPITECH PROJECT, 2022
** free_reset
** File description:
** free reset
*/

#include "minishell.h"

void free_all(ms_t *ms)
{
    my_free_array(ms->cmd);
    my_free_array(ms->env);
    free(ms->buff);
    free(ms);
}

void set_ms(ms_t *ms)
{
    ms->size = SIZE;
    ms->env = NULL;
    ms->cmd = NULL;
    ms->buff = NULL;
    ms->size_env = 0;
    ms->isatt = 0;
    ms->len_cmd = 0;
}

void set_cd(ms_t *ms, cd_t *cd)
{
    cd->ipwd = find_var(ms, "PWD=");
    cd->lpwd = len_var(ms, "PWD=");
    cd->pwd = malloc(sizeof(char) * (cd->lpwd) - 2);
    cd->lcmd = my_lenarray(ms->cmd);
    cd->iopwd = find_var(ms, "OLDPWD=");
    cd->ihome = find_var(ms, "HOME=");
    cd->lhome = len_var(ms, "HOME=") - 5;
}

void set_exec(ms_t *ms, exec_t *exc)
{
    exc->ipath = find_var(ms, "PATH=");
    exc->execp = NULL;
    exc->paths = my_str_to_array(ms->env[exc->ipath] + 5, ":");
}
