#include "shell.h"

/**
 * custom_strncpy - copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the number of characters to copy
 * Return: a pointer to the destination string
 */
char *custom_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }

    return dest;
}

/**
 * custom_strncat - concatenates two strings
 * @dest: the destination string
 * @src: the source string
 * @n: the maximum number of characters to concatenate
 * Return: a pointer to the destination string
 */
char *custom_strncat(char *dest, const char *src, size_t n)
{
    size_t dest_len = custom_strlen(dest);
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[dest_len + i] = src[i];
    }

    dest[dest_len + i] = '\0';

    return dest;
}

/**
 * custom_strchr - locates a character in a string
 * @s: the string to search
 * @c: the character to find
 * Return: a pointer to the first occurrence of the character in the string
 * or NULL if the character is not found
 */
char *custom_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (char *)s;
        s++;
    }

    if (c == '\0')
        return (char *)s;

    return NULL;
}
