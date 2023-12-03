/*
** EPITECH PROJECT, 2022
** error
** File description:
** error
*/

#include "minishell.h"

int cd_error(char *path)
{
    if (errno == EACCES) {
        my_printf("%e: Permission denied.\n", path);
        return (ERROR);
    }
    if (errno == ENOTDIR) {
        my_printf("%e: Not a directory.\n", path);
        return (ERROR);
    }
    if (errno == ENOENT) {
        my_printf("%e: No such file or directory.\n", path);
        return (ERROR);
    }
    return (TRUE);
}

int exec_error(ms_t *ms)
{
    my_printf("%e: Command not found.\n", ms->cmd[0]);
    return (ERROR);
}

int unsetenv_error(ms_t *ms)
{
    if (ms->len_cmd == 1) {
        my_perror("unsetenv: Too few arguments.\n");
        return (ERROR);
    }
    if (ms->len_cmd > 2) {
        my_perror("unsetenv: Too many arguments.\n");
        return (ERROR);
    }
    return (TRUE);
}

int setenv_error(ms_t *ms)
{
    if (my_ischar(ms->cmd[1][0])) {
        my_perror("setenv: Variable name must begin with a letter.\n");
        return (ERROR);
    }
    if (my_isnum(ms->cmd)) {
        my_perror("setenv: Variable name must contain ");
        my_perror("alphanumeric characters.\n");
        return (ERROR);
    }
    if (my_lenarray(ms->cmd) > 3) {
        my_perror("setenv: Too many arguments.\n");
        return (ERROR);
    }
    return (TRUE);
}
