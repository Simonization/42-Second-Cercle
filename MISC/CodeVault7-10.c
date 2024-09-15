#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>


//*********** 8 Introduction to FIFO


//*************/


/*********** 7 Practical use case for pipes

int	main(int argc, char *argv[])
{
	int	start;
	int	end;
	int	array[] = {1, 2, 3, 4, 1, 2};
	int	arraySize = sizeof(array) / sizeof(int);
	int fd[2];
	if (pipe(fd) == -1)
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

	int sum = 0;
	int	i;
	i = start;
	while(i < end)
	{
		sum += array[i];
		i++;
	}
	
	printf("Calculated partial sum: %d\n", sum);	

	if (id == 0)
	{
		close(fd[0]);
		if(write(fd[1], &sum, sizeof(sum)) == -1)
			return(3);
		close(fd[1]);
	}
	else
	{
		int	SumFromChild;
		close(fd[1]);
		if(read(fd[0], &SumFromChild, sizeof(SumFromChild)) == -1)
			return (4);
	}
		close(fd[0]);

		int	TotalSum = sum + SumFromChild;
		printf("Total sum is %d\n", TotalSum);
	// see line+12: we wrote to, in child porcess, you have to wait for child processes to finish
		wait(NULL);
	}	
	return (0);
}

/*****

/****** 6 Communicating betweenprocesses

***********/
