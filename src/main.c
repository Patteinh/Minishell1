/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "minishell.h"

char **malloc_env(ms_t *ms, char **env)
{
    int i = 0;
    ms->size_env = my_lenarray(env);
    ms->env = malloc(sizeof(char *) * (ms->size_env + 1));
    ms->env[ms->size_env] = NULL;

    for (; env[i]; i++)
        ms->env[i] = my_strdup(env[i]);
    ms->env[i] = NULL;
    return (ms->env);
}

int start_ms(ms_t *ms)
{
    int check = 0;

    if (isatty(ms->isatt))
        my_putstr("$>");
    my_signal();
    if (getline(&ms->buff, &ms->size, stdin) == EOF)
        return (84);
    if (my_strlen(ms->buff) > 1)
        check = my_cmd(ms);
    ms->buff = NULL;
    return (check);
}

int minishell(ms_t *ms)
{
    while (MS)
        if (start_ms(ms) == 84)
            return (84);
    free_all(ms);
    return (0);
}

int set_minishell(char **env)
{
    int ret = 0;
    ms_t *ms = malloc(sizeof(ms_t));
    set_ms(ms);
    ms->env = malloc_env(ms, env);
    if ((ret = minishell(ms)) == 84) {
        free_all(ms);
        return (84);
    }
    return (ret);
}

int main(int ac, char **av, char **env)
{
    (void)av;
    if (ac == 1)
        return (set_minishell(env));
    return (84);
}
