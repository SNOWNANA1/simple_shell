#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void display_prompt(void);
void stevefrancis_print(const char *message);
void read_command(char *command, size_t size);
void execute_command(const char *command);

#endif /* SHELL_H */
