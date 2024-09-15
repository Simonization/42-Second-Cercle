/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:29:18 by slangero          #+#    #+#             */
/*   Updated: 2024/09/06 18:24:30 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_free(char **table)
{
    if (table == NULL)
        return;
    
    int i = 0;
    while (table[i] != NULL)
    {
        free(table[i]);
        table[i] = NULL;
        i++;
    }
    
    free(table);
    table = NULL;
}

void first_cmd(char *cmd, char **env, int *fd, char *infile)
{
    char    *path;
    char    **split_cmd;
    int     file_one;
    
    file_one = open(infile, O_RDONLY);
    if (file_one == -1)
    {
        perror("Error opening file");
        exit(1);
    }
    close(fd[0]);
    dup2(file_one, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    close(file_one);
    split_cmd = ft_split(cmd, ' ');
    path = execute_command(split_cmd[0], env);
    execve(path, split_cmd, env);
    printf("Error\n");
    free(path);
    //ft_free(split_cmd);
    exit(1);
}

void sec_cmd(char *cmd, char **env, int *fd, char *outfile)
{
    char    *path;
    char    **split_cmd;
    int     file_two;

    file_two = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_two == -1)
    {
        perror("Error opening file");
        exit(1);
    }
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    dup2(file_two, STDOUT_FILENO);
    close(fd[0]);
    close(file_two);
    split_cmd = ft_split(cmd, ' ');
    path = execute_command(split_cmd[0], env);
    execve(path, split_cmd, env);
    printf("Error\n");
    free(path);
    //ft_free(split_cmd);
    exit(1);
}

void parent_process(char **av, char **env)
{
    int cmd1;
    int cmd2;
    int	fd[2];
	
    if (pipe(fd) == -1)
	{
		printf("an error occured while opening the pipe\n");
        exit(2);
	}
    cmd1 = fork();
    if (cmd1 == 0)
    {
        first_cmd(av[2], env, fd, av[1]);
    }
    else
    {
        wait(NULL);
        cmd2 = fork();
        if (cmd2 == 0)
        {
            sec_cmd(av[3], env, fd, av[4]);
        }
    }
    close(fd[0]);
    close(fd[1]);
    
    wait(NULL);

    // tout free
}