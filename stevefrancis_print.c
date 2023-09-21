#include "shell.h"

void stevefrancis_print(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
