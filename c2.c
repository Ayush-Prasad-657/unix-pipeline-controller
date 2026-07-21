/* c2.c
 * COMP2019 Systems Programming 1
 * This is a sample file for Assignment 2
 * modify it as needed to complete your solution
 * Author: Dr Evan Crawford (e.crawford@westernsydney.edu.au)
 */

#include <stdio.h>
/* stdio.h defines BUFSIZ */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* This is a simple program that reads from stdin
 * and outputs the data read to stdout
 */
int main(int ac,char**av)
{
	char buf[BUFSIZ];
	int i;


	while(fgets(buf,BUFSIZ,stdin) != NULL)
	{

		for ( i = 0; buf[i] != '\0'; i++)
		{
			if(isupper(buf[i]))
			{
				buf[i] = tolower(buf[i]);
			}
			else if (islower(buf[i]))
			{
				buf[i] = toupper(buf[i]);
			}

		}

		fputs(buf, stdout);
	}

	return 0;
}
