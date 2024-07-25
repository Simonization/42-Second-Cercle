#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

void	error_exit(char *message)
{
	write(STDERR_FILENO, message, strlen(message));
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}

void	execute_command(char *command, char **envp)
{
	char	**args;
	int	arg_count;
	char	*token = strtok(command, " ");

	while (token != NULL) 
	{
		arg_count++;
		args = realloc(args, sizeof(char*) * arg_count);
		args[arg_count - 1] = token;
		token = strtok(NULL, " ");
	}
	args = realloc(args, sizeof(char*) * (arg_count + 1));
	args[arg_count] = NULL;

	char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    char full_path[1024];

	while (dir != NULL)
	{
	snprintf(full_path, sizeof(full_path), "%s/%s", dir, args[0]);
	if (access(full_path, X_OK) == 0)
		break;
	dir = strtok(NULL, ":");
	}
	if (dir == NULL)
		error_exit("Command not found: %s", args[0]);
	if (execve(full_path, args, envp) == -1)
        error_exit("Failed to execute command: %s", args[0]);
}

int	main(int argc, char *argv[], char **envp)
{
	int fd[2];
	pid_t pid1, pid2;

	if (argc !=5)
		error_exit("Usage: ./pipex file1 cmd1 cmd2 file2");

	if (pipe(fd) == -1)
		error_exit("Pipe error");

	pid1 = fork();
	if (pid1 == -1)
		error_exit("Fork error");

	if (pid1 == 0)
	{
    close(fd[0]);
    int input_fd = fopen(argv[1], O_RDONLY);
    if (input_fd == -1)
        error_exit("Error opening input file");
    
    if (dup2(input_fd, STDIN_FILENO) == -1)
        error_exit("Error redirecting input");
    close(input_fd);

    // Step 3: Redirect output to pipe
    if (dup2(fd[1], STDOUT_FILENO) == -1)
        error_exit("Error redirecting output to pipe");
    close(fd[1]);

    // Step 4: Execute cmd1
    execute_command(argv[2], envp);

    // If we reach here, execution failed
    error_exit("Failed to execute cmd1");

		
	}

	pid2 = fork();
	if (pid2 == -1)
		error_exit("Fork error");

	if (pid2 == 0)
	{
		// redirect input from the read end of the pipe (use dup2() )
		// redirect output to file2 (use open and dup2() )
		// execute cmd2 (execute_command)
	}

	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return (0);
}

int	child1(void)
{

}

int	child2(void)
{

}
