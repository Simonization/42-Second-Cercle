#include "pipex.h"

int check_args(int ac)
{
    if (ac != 5)
    {
        ft_printf("%s", "invalid number of Arguments");
        exit (0);
    }
    return 0;
}

int main(int ac, char** av, char**env)
{
    int pipe_fd[2];
    pid_t pid;

    check_args(ac);
    if(pipe(pipe_fd) == -1)
    {
        ft_printf("%s", "pipe doesnt work\n");
        exit (0);
    }
    pid = fork();
    if (pid == -1)
        child_process(av, pipe_fd, env);
    waitpid(pid, NULL, 0);
    parent_process(av, pipe_fd, env);
    return (0);
}