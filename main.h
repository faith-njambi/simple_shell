#ifndef MAIN_H
#define MAIN_H

char **_strtow(char *str);
int _putchar(char c);
int readline(void);

int read_a_line(void);
char *argstostr(int ac, char *av[]);
void exec_ve(char **a, char **b, char **c);

char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

#endif
