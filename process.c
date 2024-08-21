/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:29:18 by slangero          #+#    #+#             */
/*   Updated: 2024/08/21 19:00:20 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void child_process(char **av, int *pipe_fd, char **env)
{
    int fd;
    
    fd = open(av[0], O_RDONLY, 0777);
    if (fd == -1)
    {
        ft_printf("%s", "file 1 invalid\n");
        exit (0);
    }
    dup2(fd, 0);
    dup2(pipe_fd[1], 1);
    close(pipe_fd[0]);
    execute_command(av[1], env);
}

void parent_process(char **av, int *pipe_fd, char **env)
{
    int fd;
    
    fd = open(av[3], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd == -1)
    {
        ft_printf("%s", "file 2 invalid\n");
        exit (0);
    }
    dup2(fd, 1);
    dup2(pipe_fd[0], 0);
    close(pipe_fd[1]);
    execute_command(av[2], env);
}

void execute_command(char cmd, char **env)
{
    // cherche le bon path dans le env (prendre la bonne ligne) -> get_env
    substrs 5 (PATH=)
    // couper en petits bouts le path (ft_split entre le ":") et tester chaque petit bout -> get_path
    if (execve(/*path du bout qui est bon */) == -1)
    {
        //free;
    }
    
}