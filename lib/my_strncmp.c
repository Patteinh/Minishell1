/*
** EPITECH PROJECT, 2022
** my_strcomp.c
** File description:
** check n char
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] && s2[i] && i + 1 < n && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}
