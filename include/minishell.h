/*
** EPITECH PROJECT, 2022
** projet.h
** File description:
** projet.h
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include "my.h"

#ifndef _MINISHELL_H
    #define _MINISHELL_H
    #define SIZE 32
    #define MS 1
    #define SUCCESS 0
    #define TRUE 0
    #define FALSE 1
    #define ERROR 1
    #define WORD_EXIST -1

typedef struct st_ms {
    size_t size;
    char **env;
    char **cmd;
    char *buff;
    int isatt;
    int size_env;
    int len_cmd;
} ms_t;

typedef struct st_cd {
    char *pwd;
    int lcmd;
    int ipwd;
    int lpwd;
    int iopwd;
    int ihome;
    int lhome;
} cd_t;

typedef struct st_exec {
    DIR *path;
    struct dirent *file;
    int ipath;
    char *execp;
    char **paths;
} exec_t;

int  set_minishell(char **env);
void set_ms(ms_t *ms);
char **malloc_env(ms_t *ms, char **env);
int  minishell(ms_t *ms);
int  start_ms(ms_t *ms);
void my_signal(void);
void segfault();
void ctrl_c();
int  my_cmd(ms_t *ms);
int  my_cmd_two(ms_t *ms);
int  my_cmd_three(ms_t *ms);
int  search_cmd(ms_t *ms);
int  my_exit(ms_t *ms);
int  my_env(ms_t *ms);
int  my_setenv(ms_t *ms);
int  my_unsetenv(ms_t *ms);
int  my_cd(ms_t *ms);
int  check_space_tab(ms_t *ms);
int  search_cmd(ms_t *ms);
int  set_setenv(ms_t *ms);
int  setenv_two(ms_t *ms);
int  setenv_three(ms_t *ms);
int  check_value_exist(ms_t *ms);
int  setenv_error(ms_t *ms);
char **realloc_env(char **env, int i);
int  reset_word_find(ms_t *ms, int check);
int  reset_value_add_word(ms_t *ms, int check, int i);
int  add_value_word_not_find(ms_t *ms, int check);
int  add_value_word_find(ms_t *ms, int check, int i);
int  unset(ms_t *ms);
int  unsetenv_error(ms_t *ms);
void set_cd(ms_t *ms, cd_t *cd);
int  go_home(ms_t *ms, cd_t *cd);
int  go_last_path(ms_t *ms, cd_t *cd);
int  go_back(ms_t *ms, cd_t *cd);
int  go_path(char *path);
int  len_home(ms_t *ms);
char *path_home(ms_t *ms, char *home, int ihome);
int  find_var(ms_t *ms, const char *tmp);
int  len_var(ms_t *ms, const char *tmp);
void change_oldpwd(ms_t *ms, cd_t *cd);
int  cd_error(char *path);
void set_exec(ms_t *ms, exec_t *exc);
int  exec_cmd(ms_t *ms, char *exec_cmd);
int  find_exec_path(ms_t *ms, exec_t *exc, int i);
int  exec_error(ms_t *ms);
void reset_all(ms_t *ms);
void free_exc(exec_t *exc);
void free_all(ms_t *ms);

#endif
