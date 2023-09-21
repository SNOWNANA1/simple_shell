#include "shell.h"

void stevefrancis_print(const char *our_special_print_function) {
	write(STDOUT_FILENO, our_special_print_function, strlen(our_special_print_function));
