#include "shell.h"

void execute_string(const char *message) {
	pid_t child_pid = fork(); /* create a childs process */

	if (child_pid == -1) {
	    perror("fork");
	    exit(EXIT_FAILURE);
	 } else if (child_pid == 0) {
		/* child process */
		execlp(message, msessage (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	 } else {
	     /* parent process */
	     wait(NULL);
	 }
