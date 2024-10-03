/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:13:17 by slangero          #+#    #+#             */
/*   Updated: 2024/10/03 19:24:58 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirection_io_first(int *fd, const char *infile)
{
	int	file_one;

	file_one = open(infile, O_RDONLY);
	if (file_one == -1)
	{
		perror("Error opening file");
		exit(1);
	}
	close(fd[STDIN_FILENO]);
	if (dup2(file_one, STDIN_FILENO) == -1
		|| dup2(fd[STDOUT_FILENO], STDOUT_FILENO) == -1)
	{
		perror("Error duplicating file descriptor");
		exit(1);
	}
	close(fd[STDOUT_FILENO]);
	close(file_one);
}

void	redirection_io_second(int *fd, const char *outfile)
{
	int		file_two;

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
}
