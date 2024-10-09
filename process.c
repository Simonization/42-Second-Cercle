/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:29:18 by slangero          #+#    #+#             */
/*   Updated: 2024/10/09 11:38:51 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(char *cmd, char **env, int *fd, char *infile)
{
	redirection_io_first(fd, infile);
	execute_command(cmd, env);
}

void	sec_cmd(char *cmd, char **env, int *fd, char *outfile)
{
	redirection_io_second(fd, outfile);
	execute_command(cmd, env);
}

void	second_fork(char *command, char *outfile, char **env, int *fd)
{
	pid_t	cmd2;

	cmd2 = fork();
	if (cmd2 == -1)
	{
		perror("Error forking second child");
		exit(1);
	}
	else if (cmd2 == 0)
		sec_cmd(command, env, fd, outfile);
}
void	first_fork(char *command, char *infile, char **env, int *fd)
{
	pid_t	cmd1;

	cmd1 = fork();
	if (cmd1 == -1)
	{
		perror("Error forking first child");
		exit(1);
	}
	else if (cmd1 == 0)
		first_cmd(command, env, fd, infile);
}

int	parent_process(char **av, char **env)
{
	int	fd[2];

	if (pipe(fd) == -1)
	{
		perror("Error creating pipe");
		exit(2);
	}
	first_fork(av[2], av[1], env, fd);
	second_fork(av[3], av[4], env, fd);
	if (close(fd[STDIN_FILENO]) == -1)
		perror(NULL);
	if (close(fd[STDOUT_FILENO]) == -1)
		perror(NULL);
	wait(NULL);
	wait(NULL);
	return (0);
}
