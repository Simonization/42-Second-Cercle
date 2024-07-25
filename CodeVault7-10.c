#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>


//*********** 7 Practical use case for pipes

int	main(int argc, char *argv[])
{
	int	array[] = {1, 2, 3, 4, 1, 2, };
	int	arraySize = sizeof(arr) / sizeof(int);
	int fd[2];
	if pipe(fd) == -1)
		return (1);

	int	id = fork();
	if (id == -1)
		return (2);
	if (id == 0)
	{
		start = 0;
		end = start + arraySize / 2;;
	}
	else
	{
		start = arraySize / 2;
		end = arraySize;
	}
	while(i < end)
	{
		i = start;
		i++;
	}
	int sum = 0;
	int	i;

	return (0);
}

//*****

/****** 6 Communicating betweenprocesses

***********/
