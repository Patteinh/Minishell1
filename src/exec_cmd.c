/*
** EPITECH PROJECT, 2022
** exec_cmd.c
** File description:
** exec bin command
*/

#include "minishell.h"

void check_segfault(int ret)
{
    if (WIFSIGNALED(ret) != 0) {
        if ((WTERMSIG(ret) == 11) && (__WCOREDUMP(ret) == 0))
            my_perror("Segmentation fault\n");
        else if ((WTERMSIG(ret) == 11) && (__WCOREDUMP(ret) != 0))
            my_perror("Segmentation fault (core dumped)\n");
    }
}

int exec_cmd(ms_t *ms, char *exec_cmd)
{
    pid_t cpid;
    pid_t chpid;
    cpid = fork();
    int ret;

    if (cpid == 0) {
        if ((execve(exec_cmd, ms->cmd, ms->env)) == -1)
            exec_error(ms);
        exit(0);
    } else if (cpid > 0)
        ((chpid = wait(&ret)) < 0) ? my_perror("wait"), exit(0) : 0;
    check_segfault(ret);
    return (ret);
}

int search_cmd(ms_t *ms)
{
    exec_t *exc = malloc(sizeof(exec_t));
    set_exec(ms, exc);

    for (int i = 0; exc->paths[i]; i++) {
        exc->path = opendir(exc->paths[i]);
        if (exc->path)
            while ((exc->file = readdir(exc->path)))
                if (!my_strcmp(exc->file->d_name, ms->cmd[0])) {
                    exc->execp = my_strcat(exc->paths[i], "/");
                    exc->execp = my_strcat(exc->execp, exc->file->d_name);
                    my_free_array(exc->paths);
                    return (exec_cmd(ms, exc->execp));
                }
    }
    my_free_array(exc->paths);
    return (exec_error(ms));
}
