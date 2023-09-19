#include "shell.h"

/**
 * read_input - reads user input from STDIN
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t read_input(info_t *info)
{
    static char *buffer = NULL; /* Input buffer */
    static size_t buf_len = 0; /* Length of the buffer */
    ssize_t bytes_read;

    if (buffer == NULL || buf_len == 0)
    {
        /* Initialize the buffer */
        buffer = NULL;
        buf_len = 0;
    }

    /* Read input from the user */
    bytes_read = getline(&buffer, &buf_len, stdin);

    if (bytes_read == -1) /* EOF or error */
        return -1;

    /* Remove trailing newline character if present */
    if (bytes_read > 0 && buffer[bytes_read - 1] == '\n')
        buffer[bytes_read - 1] = '\0';

    /* Process the input, e.g., store it in a history list */
    process_input(info, buffer);

    return bytes_read;
}

/**
 * process_input - processes the user input
 * @info: parameter struct
 * @input: user input string
 *
 * Return: void
 */
void process_input(info_t *info, char *input)
{
    /* Implement your input processing logic here */
    /* For example, you can store the input in a history list */
    add_to_history(info, input);
    /* You can also tokenize the input and execute commands */
    tokenize_and_execute(info, input);
}
