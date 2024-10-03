// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>
// #include <sys/wait.h>
// #include <errno.h>



// int	main(int argc, char *argv[])
// {
// 	int	fd[2];
// 	if (pipe(fd) == -1)
// 	{
// 		printf("an error occured while opening the pipe\n");
// 		return 1;
// 	}
// 	int id = fork();
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		int		x;
// 		printf("input a number: ");
// 		scanf("%d", &x);
// 		if (write(fd[1], &x , sizeof(int)) == -1)
// 		{
// 			printf("an error occured while writing to the pipe\n");
// 			return (2);
// 		}
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		int	y;
// 		// in childprocess hereabove, x got written into the pipe. you tell him how many bytes to write (sizeofint), and it reads that many bytes
// 		read(fd[0], &y, sizeof(int));
// 			printf("an error occured while reading from the pipe\n");
// 			return (2);
// 		close(fd[0]);
// 		printf("got from childprocess %d\n", y);
// 	}
// 	return (0);
// }
// // whenever you read and write , you should check for errors (if -1)
// /****************/
// /****************
// int main(int argc, char *argv[])
// {
// 	int	id1;
// 	int	id2;

// 	id1 = fork();
// 	id2 = fork();
// 	if (id1 == 0)
// 	{
// 		if (id2 == 0)
// 			printf("We are Process y\n");
// 		else
// 			printf("We are Process x\n");
// 	}
// 	else
// 	{
// 	if (id2 == 0)
// 		printf("We are process z\n");
// 	else
// 		printf("We are the parent process!\n"); 
// 	}
// 	while(wait(NULL) != -1 || errno != ECHILD)
// 		printf("WAITED FOR A CHILD TO FINISH\n");
// 	return (0);
// }
// ************/
// /**************
// int	main(int argc, char *argv[])
// {
// 	int	id;

// 	id = fork();
// 	if (id == 0)
// 		sleep(1);
// 	printf("Current ID: %d\nParent ID: %d\n", getpid(), getppid());
// 	return (0);
// }
// *******/
// /***************************
// int	main(int argc, char *argv[])
// {
// 	int	id;

// 	id = fork();
// 	if(id != 0)
// 	{
// 		printf("coucou");
// 	}
// 	else
// 		printf("maman");
// 	return (0);
// }
// ******************/
// /******************wait****************
// int main(int argc, char* argv[])
// {
// 	int	id;
	
// 	id = fork();
// 	//printf("Hello world from id : %d\n", id);
// 	if (id == 0)
// 	{
// 		printf("Hello from child process\n");
// 	}
// 	if (id != 0)
// 		wait(NULL);
// 	if (id != 0)
// 	{
// 		fork();
// 	}
// 	printf("Hello world from id : %d\n", id);
// 	return (0);
// }	
// ***************************************/
