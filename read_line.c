#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * readline - Reads a strings from stdin
 *
 * Return: number of chars read
 */
int readline(void)
{

	int count = 0;
	char buf[72];
	char *buf_ptr;
	int char_r = 0;
	int char_w = 0;


		do {
		write(1, "#cisfun$ ", 9);
			char_r = read(0, buf, 72);
			if (char_r > 0)
			{
				buf_ptr = buf;
				count += char_r;
				while (char_r > 0)
				{
					char_w = write(STDOUT_FILENO, buf_ptr, char_r);
					if (char_w < 0)
						perror("Error: ");
					char_r -= char_w;
					buf_ptr += char_w;
				}
			}
			else if (char_r < 0)
				perror("Read: ");
			else
				break;
		} while (1);
	return (count);
}
/*
 *	do {
 *
 * } while (1);
 */
