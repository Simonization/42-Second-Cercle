// #include "pipex.h"
// #include "process.c"

// void execute_command(char cmd, char **env)
// {
//     printf("%s", *env);

// 	// cherche le bon path dans le env (prendre la bonne ligne) -> get_env
    
//  //   substrs 5 (PATH=)
//     // couper en petits bouts le path (ft_split entre le ":") et tester chaque petit bout -> get_path
// //    if (execve(/*path du bout qui est bon */) == -1)
//     {
//         //free;
//     }  
// }

// int check_args(int ac)
// {
//     if (ac != 5)
//     {
//         printf("%s", "invalid number of Arguments");
//         exit (0);
//     }
//     return 0;
// }

// int main(int ac, char** av, char**env)
// {
//     execute_command(*av[1] , env);
// 	/*
// 	int pipe_fd[2];
//     pid_t pid;

//     check_args(ac);
//     if(pipe(pipe_fd) == -1)
//     {
//         ft_printf("%s", "pipe doesnt work\n");
//         exit (0);
//     }
//     pid = fork();
//     if (pid == -1)
//         child_process(av, pipe_fd, env);
//     waitpid(pid, NULL, 0);
//     parent_process(av, pipe_fd, env);
//     */
// 	return (0);
// }

// /*  boulot de l'enfant : 
//     cmd = ft_split(av[2], ' ');
//     path = execute_command(cmd[0], env);
//     execve(path, cmd, env);
//     printf("coucou\n");
// */
