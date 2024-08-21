/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 21:49:40 by slangero          #+#    #+#             */
/*   Updated: 2024/08/12 21:47:21 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *message)
{
	ft_printf("%s\n", message);
	exit(1);
}

void	**parse_argument(char *command, int *arg_count)
{
	char	**args;
	char	*token;

	*arg_count = 0;
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		(*arg_count)++;
		args = realloc(args, sizeof(char *) * *arg_count);
		args[*arg_count - 1] = token;
		token = strtok(NULL, " ");
	}
	args = realloc(args, sizeof(char *) * (arg_count + 1));
	args[arg_count] = NULL;
}

char *find_executable(char *command)
{
	char *path;
    char *path_copy;
    char *dir;
    char full_path[1024];

	path = getenv("PATH");
    path_copy = strdup(path);
    dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
			return full_path;
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return NULL;
}

void execute_command(char *command, char **envp)
{
	int	arg_count;
	char **args;
	char	*full_path;

	args = parse_arguments(command, &arg_count;
	full_path = find_executable(args[0]);

	if (full_path == NULL)
		error_exit("Command not found");

	if (execve(full_path, args, envp) == -1)
		error_exit("Failed to execute command");

	free(full_path);
	free(args);
}

int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		input_fd;
	int		output_fd;

	if (argc != 5)
		error_exit("Usage: ./pipex file1 cmd1 cmd2 file2");
	if (pipe(fd) == -1)
		error_exit("Pipe error");
	pid1 = fork();
	if (pid1 == -1)
		error_exit("Fork error");
	if (pid1 == 0)
	{
		close(fd[0]);
		input_fd = fopen(argv[1], O_RDONLY);
		if (input_fd == -1)
			error_exit("Error opening input file");
		if (dup2(input_fd, STDIN_FILENO) == -1)
			error_exit("Error redirecting input");
		close(input_fd);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			error_exit("Error redirecting output to pipe");
		close(fd[1]);
		execute_command(argv[2], envp);
		error_exit("Failed to execute cmd1");
	}
	pid2 = fork();
	if (pid2 == -1)
		error_exit("Fork error");
	if (pid2 == 0)
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			error_exit("Error redirecting input from pipe");
		close(fd[0]);
		int output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (output_fd == -1)
			error_exit("Error opening output file");
		if (dup2(output_fd, STDOUT_FILENO) == -1)
			error_exit("Error redirecting output to file");
		close(output_fd);
		execute_command(argv[3], envp);
		error_exit("Failed to execute cmd2");
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
