#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdarg.h>
#include "libft.h"



char    *execute_command(char *cmd, char **env);
char    *access_path(char **path, char *cmd);

void first_cmd(char *cmd, char **env, int *fd, char *infile);
void sec_cmd(char *cmd, char **env, int *fd, char *outfile);
void parent_process(char **av, char **env);

#endif