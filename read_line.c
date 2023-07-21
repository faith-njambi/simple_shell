#include <unistd.h>
#include <stdio.h>
#include "../main.h"


int readline(void);
/**
 * main - starting point
 * @ac: argument counter
 * @av: argument array
 *
 * Return: number of characters read, -1 on failure
int main(void)
{
	readline();
}
 */

/**
 * readline - read input from user and prints it
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
		do {
		write(1, "$ ", 3);
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
	} while (1);
	return (count);
}