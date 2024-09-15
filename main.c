#include "pipex.h"


int check_args(int ac)
{
    if (ac != 5)
    {
        printf("%s\n", "invalid number of arguments");
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (check_args(ac))
    {
    parent_process(av, env);
    }
    return (0);
}