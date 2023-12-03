/*
** EPITECH PROJECT, 2022
** commands
** File description:
** commands
*/

#include "minishell.h"

int check_space_tab(ms_t *ms)
{
    if (ms->cmd[0] == NULL || !my_strcmp(ms->cmd[0], " ")
        || !my_strcmp(ms->cmd[0], "\t") || !my_strcmp(ms->cmd[0], "\0"))
        return (ERROR);
    return (TRUE);
}

int choice_cmd(ms_t *ms, int nbchoice)
{
    switch (nbchoice) {
        case 0 :
            return (my_cd(ms));
        case 1 :
            return (my_env(ms));
        case 2 :
            return (my_setenv(ms));
        case 3 :
            return (my_unsetenv(ms));
        case 4 :
            return (my_exit(ms));
    }
    return (ERROR);
}

int count_choice(ms_t *ms, char **choice, int nb)
{
    for (; nb != 5; nb++)
        if (!my_strcmp(ms->cmd[0], choice[nb]))
            break;
    return (nb);
}

int my_cmd(ms_t *ms)
{
    int nb = 0;
    char **choice = my_str_to_array("cd env setenv unsetenv exit", " ");
    ms->cmd = my_str_to_array(ms->buff, " \n\t");
    ms->len_cmd = my_lenarray(ms->cmd);
    nb = count_choice(ms, choice, nb);
    my_free_array(choice);

    if (check_space_tab(ms))
        return (ERROR);
    if (nb == 5)
        return (search_cmd(ms));
    return (choice_cmd(ms, nb));
}
