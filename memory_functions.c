#include "shell.h"

/**
 * custom_free - custom memory deallocation function
 * @ptr: address of the pointer to deallocate
 *
 * This function frees the memory pointed to by ptr and sets it to NULL.
 * Additionally, it prints a message to the console.
 *
 * Returns: 1 if freed, otherwise 0.
 */
int custom_free(void **ptr)
{
    if (ptr && *ptr)
    {
        printf("Print memory for shell...\n");
        free(*ptr);
        *ptr = NULL;
        return (1);
    }
    return (0);
}
