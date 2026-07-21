/* c3.c
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
	int lineNumber = 1;


	while(fgets(buf,BUFSIZ,stdin) != NULL)
	{
		printf("%d %s", lineNumber, buf);
		lineNumber++;	
	}

	return 0;
}
