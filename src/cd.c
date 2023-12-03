/*
** EPITECH PROJECT, 2022
** cd
** File description:
** cd cmd
*/

#include "minishell.h"

int go_path(char *path)
{
    DIR *dir = opendir(path);

    if (!dir)
        return (cd_error(path));
    chdir(path);
    closedir(dir);
    return (TRUE);
}

int go_last_path(ms_t *ms, cd_t *cd)
{
    ms->env[cd->ipwd] = my_strcat("PWD=", ms->env[cd->iopwd] + 7);
    change_oldpwd(ms, cd);
    chdir(ms->env[cd->ipwd] + 4);
    return (TRUE);
}

int go_back(ms_t *ms, cd_t *cd)
{
    change_oldpwd(ms, cd);
    chdir(ms->cmd[1]);
    getcwd(cd->pwd, cd->lpwd - 3);
    cd->pwd = my_strcat("PWD=", cd->pwd);
    ms->env[cd->ipwd] = my_strdup(cd->pwd);
    return (TRUE);
}

int go_home(ms_t *ms, cd_t *cd)
{
    char *path = malloc(sizeof(char) * (cd->lpwd + 1));
    char *home = malloc(sizeof(char) * (cd->lhome + 1));
    char *tmp = NULL;

    change_oldpwd(ms, cd);
    getcwd(path, cd->lpwd);
    path[cd->lpwd] = '\0';
    tmp = path;
    path = my_strcat("PWD=", path);
    free(tmp);
    home = path_home(ms, home, cd->ihome);
    chdir(home);
    ms->env[cd->ipwd] = my_strcat("PWD=", home);
    free(home);
    free(path);
    return (TRUE);
}
