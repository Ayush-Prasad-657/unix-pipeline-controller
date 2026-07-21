/* c1.c
 * COMP2019 Systems Programming 1
 * This is a sample file for Assignment 2
 * modify it as needed to complete your solution
 * Author: Dr Evan Crawford (e.crawford@westernsydney.edu.au)
 */

#include <stdio.h>
/* stdio.h defines BUFSIZ */
#include <stdlib.h>
#include <string.h>

/* This is a simple program that reads from stdin
 * and outputs the data read to stdout
 */
int main(int ac,char**av)
{
	char buf[BUFSIZ];

	fprintf(stderr, "Please enter the next line of input:\n");

	while (fgets(buf, BUFSIZ, stdin) != NULL)
	{
		fputs(buf, stdout);

		fprintf(stderr, "Please enter the next line of input:\n");
	}
	

	return 0;
}
