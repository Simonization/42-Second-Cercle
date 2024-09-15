#include "pipex.h"

char    *execute_command(char* cmd, char **env)
{
    char    **table;
    char    **path;
    int i;

    path = NULL;
    i = 0;
    while(env[i])
    {
        if(strncmp(env[i], "PATH=", 5) == 0)
        {
            table = ft_split(env[i], '=');
            path = ft_split(table[1], ':');
            //ft_free(table);
        }
        i++;
    }
    i = 0;
    return (access_path(path, cmd));
}

char    *access_path(char **path, char *cmd)
{
    char *tmp;
    char *c_path;
    int i;

    i = 0;
    tmp = ft_strjoin("/", cmd);
    while (path[i])
    {
        c_path = ft_strjoin(path[i], tmp);
        if(access(c_path, X_OK) == 0)
        {
            printf("Executable found: %s\n", c_path);
            free(tmp);
            return (c_path);
        }
        free(c_path);
        i++;
    }
    free(tmp);
    return (NULL);
}