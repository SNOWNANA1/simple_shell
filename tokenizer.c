#include <stdio.h>
#include <string.h>

int main() {
	char input_string[] = "stephen,and,francis";

	// Variable initialization for tokenization
	char *token;
	char *delim = ",";

	// Start tokenization process
	token = strtok(input_string, delim);
	

	while (token != NULL) {
	    printf("Token: %s\n", token); // print out the current token
	token = strtok(NULL,delim); // Pass NULL to continue tokenization
}

return 0;

