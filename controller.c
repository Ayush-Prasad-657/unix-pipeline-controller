/* controller.c
 * COMP2019 Systems Programming 1
 * This is a sample file for Assignment 2
 * modify it as needed to complete your solution
 * Author: Dr Evan Crawford (e.crawford@westernsydney.edu.au)
 */


#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>




int main(int ac, char**av)
{


	pid_t c1,c2,c3;
	int pipe1[2],pipe2[2];
	int status;

	if (pipe(pipe1) == -1)
	{
		perror("pipe1");
		exit(1);
	}

	if (pipe(pipe2) == -1)
	{
		perror("pipe2");
		exit(1);
	}

	c1 = fork();

	if (c1 == -1)
	{
		perror("fork c1");
		exit(1);
	}

	if (c1 == 0)
	{
		dup2(pipe1[1], STDOUT_FILENO);

		close(pipe1[0]);
		close(pipe1[1]);
		close(pipe2[0]);
		close(pipe2[1]);

		execl("./c1", "c1", NULL);

		perror("execl c1");
		exit(1);
	}


	c2 = fork();

	if (c2 == -1)
	{
		perror("fork c2");
		exit(1);
	}

	if (c2 == 0)
	{
		dup2(pipe1[0], STDIN_FILENO);
		dup2(pipe2[1], STDOUT_FILENO);


		close(pipe1[0]);
		close(pipe1[1]);
		close(pipe2[0]);
		close(pipe2[1]);

		execl("./c2", "c2", NULL);

		perror("execl c2");
		exit(1);
	}


	c3 = fork();

	if (c3 == -1)
	{
		perror("fork c3");
		exit(1);
	}

	if (c3 == 0)
	{
		dup2(pipe2[0], STDIN_FILENO);


		close(pipe1[0]);
		close(pipe1[1]);
		close(pipe2[0]);
		close(pipe2[1]);

		execl("./c3", "c3", NULL);

		perror("execl c3");
		exit(1);
	}

	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[0]);
	close(pipe2[1]);
	
	waitpid(c1, &status, 0);
	printf("c1 exited with status %d\n", WEXITSTATUS(status));

	waitpid(c2, &status, 0);
	printf("c2 exited with status %d\n", WEXITSTATUS(status));

	waitpid(c3, &status, 0);
	printf("c3 exited with status %d\n", WEXITSTATUS(status));

	return 0;
	
	
	/* add your solution here */
}
