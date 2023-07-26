#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../main.h"
#include <string.h>
#include <sys/wait.h>

/**
 * main - starting point of shell program
 * @ac: argument count
 * @av: argument vector
 * @env: pointer to environmental variables
 *
 * Return: 0 success
 */
int main(int ac, char **av, __attribute__((__unused__))char **env)
{
	int p = 0;
	int q = 0;
	int stat;
	pid_t pid;
	char *line;
	char **exec_str = malloc(16 * sizeof(char *));
	char *cd = "cd";
	char *parsed;
	int idx = 0;

	char *term = "exit";
	int n;
	/*
	 * char *echo = "echo";
	 */
	do {

		write(1, "sh-> ", 5);
		line = argstostr(ac, av);
		
		parsed = strtok(line, " ");
		while (parsed != NULL)
		{
			exec_str[idx] = parsed;
			parsed = strtok(NULL, " ");
			idx++;
		}
		if (ac == 3)
		{
			if (strcmp(av[1], cd) == 0)
				chdir(av[2]);
		}
		pid  = fork();
		if (pid == 0)
		{
			execve(exec_str[0], exec_str, NULL);
			read_a_line();
		}
		else if (pid < 0)
			perror("Fork: ");
		else
			wait(&stat);
	} while (1);
	return (0);
}
