#include "shell.h"

/**
 * _myenv - prints the current environment variables
 * @info: structure containing potential arguments
 * Return: Always 0
 */
int _myenv(info_t *info)
{
    print_environment(info->env);
    return (0);
}

/**
 * _getenv - gets the value of an environment variable
 * @info: structure containing potential arguments
 * @name: environment variable name
 *
 * Return: the value of the environment variable or NULL if not found
 */
char *_getenv(info_t *info, const char *name)
{
    list_t *node = info->env;
    char *p;

    while (node)
    {
        p = starts_with(node->str, name);
        if (p && *p)
            return (p);
        node = node->next;
    }
    return (NULL);
}

/**
 * _mysetenv - sets a new environment variable or modifies an existing one
 * @info: structure containing potential arguments
 *
 * Return: Always 0
 */
int _mysetenv(info_t *info)
{
    if (info->argc != 3)
    {
        _eputs("Usage: setenv VARIABLE VALUE\n");
        return (1);
    }
    if (_setenv(info, info->argv[1], info->argv[2]) == 0)
        return (0);
    return (1);
}

/**
 * _myunsetenv - removes an environment variable
 * @info: structure containing potential arguments
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
    if (info->argc == 1)
    {
        _eputs("Usage: unsetenv VARIABLE [VARIABLE...]\n");
        return (1);
    }
    for (int i = 1; i < info->argc; i++)
        _unsetenv(info, info->argv[i]);

    return (0);
}

/**
 * populate_env_list - populates the environment linked list
 * @info: structure containing potential arguments
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
    list_t *node = NULL;
    size_t i;

    for (i = 0; environ[i]; i++)
        add_node_end(&node, environ[i], 0);
    info->env = node;
    return (0);
}
