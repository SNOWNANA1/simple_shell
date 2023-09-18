#include "mylist.h"

/**
 * count_nodes - Counts the number of nodes in a linked list
 * @head: Pointer to the first node of the list
 *
 * Return: Number of nodes in the list
 */
size_t count_nodes(const list_t *head)
{
    size_t count = 0;

    while (head)
    {
        count++;
        head = head->next;
    }

    return count;
}

/**
 * list_to_array - Converts a linked list to an array of strings
 * @head: Pointer to the first node of the list
 *
 * Return: Array of strings
 */
char **list_to_array(list_t *head)
{
    size_t count = count_nodes(head);
    char **array = malloc(sizeof(char *) * (count + 1));

    if (!array)
        return NULL;

    for (size_t i = 0; i < count; i++)
    {
        array[i] = strdup(head->str);
        if (!array[i])
        {
            for (size_t j = 0; j < i; j++)
                free(array[j]);
            free(array);
            return NULL;
        }
        head = head->next;
    }

    array[count] = NULL;
    return array;
}

/**
 * print_linked_list - Prints the elements of a linked list
 * @head: Pointer to the first node of the list
 *
 * Return: Number of nodes in the list
 */
size_t print_linked_list(const list_t *head)
{
    size_t count = 0;

    while (head)
    {
        printf("%s\n", head->str ? head->str : "(nil)");
        head = head->next;
        count++;
    }

    return count;
}

/**
 * find_node_by_prefix - Finds the first node whose string starts with a prefix
 * @head: Pointer to the first node of the list
 * @prefix: Prefix to match
 * @c: Next character to match after the prefix
 *
 * Return: Pointer to the matching node or NULL if not found
 */
list_t *find_node_by_prefix(list_t *head, char *prefix, char c)
{
    while (head)
    {
        if (starts_with(head->str, prefix) && (c == -1 || head->str[strlen(prefix)] == c))
            return head;
        head = head->next;
    }

    return NULL;
}

/**
 * get_node_index - Gets the index of a node in the linked list
 * @head: Pointer to the first node of the list
 * @node: Pointer to the node to find
 *
 * Return: Index of the node or -1 if not found
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
    ssize_t index = 0;

    while (head)
    {
        if (head == node)
            return index;
        head = head->next;
        index++;
    }

    return -1;
}
