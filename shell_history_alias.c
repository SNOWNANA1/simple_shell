#include "shell.h"

/**
 * display_history - displays the command history
 * @info: struct containing command history
 *
 * Return: Always 0
 */
int display_history(info_t *info)
{
    /* Display the command history with line numbers */
    list_t *current = info->history;
    int line_number = 0;

    while (current)
    {
        printf("%d: %s\n", line_number, current->str);
        current = current->next;
        line_number++;
    }

    return (0);
}

/**
 * add_alias - adds an alias command
 * @info: struct containing aliases
 * @alias: the alias command to add
 *
 * Return: Always 0 on success, 1 on error
 */
int add_alias(info_t *info, char *alias)
{
    /* Add an alias command to the list */
    return (add_node_end(&(info->aliases), alias, 0) == NULL ? 0 : 1);
}

/**
 * remove_alias - removes an alias command
 * @info: struct containing aliases
 * @alias: the alias command to remove
 *
 * Return: Always 0 on success, 1 on error
 */
int remove_alias(info_t *info, char *alias)
{
    /* Remove an alias command from the list */
    int index = get_node_index(info->aliases, node_starts_with(info->aliases, alias, '='));

    if (index != -1)
    {
        return (delete_node_at_index(&(info->aliases), index) == NULL ? 0 : 1);
    }
    return 1; /* Alias not found */
}

/**
 * display_aliases - displays the alias commands
 * @info: struct containing aliases
 *
 * Return: Always 0
 */
int display_aliases(info_t *info)
{
    /* Display alias commands */
    list_t *current = info->aliases;

    while (current)
    {
        printf("%s\n", current->str);
        current = current->next;
    }

    return (0);
}

/**
 * alias_builtin - handles the alias builtin command
 * @info: struct containing alias commands
 *
 * Return: Always 0
 */
int alias_builtin(info_t *info)
{
    int i = 0;

    if (info->argc == 1)
    {
        /* Display alias commands if no arguments provided */
        display_aliases(info);
        return (0);
    }

    /* Handle adding and removing aliases */
    for (i = 1; info->argv[i]; i++)
    {
        if (_strchr(info->argv[i], '='))
        {
            /* Add an alias */
            if (add_alias(info, info->argv[i]) == 0)
                printf("Alias added: %s\n", info->argv[i]);
            else
                printf("Error adding alias: %s\n", info->argv[i]);
        }
        else
        {
            /* Remove an alias */
            if (remove_alias(info, info->argv[i]) == 0)
                printf("Alias removed: %s\n", info->argv[i]);
            else
                printf("Error removing alias: %s\n", info->argv[i]);
        }
    }

    return (0);
}
