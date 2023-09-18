#include "shell.h"

/**
 * is_custom_cmd - determines if a file is a custom command and is executable
 * @info: the info struct
 * @path: path to the file
 * @cmd: the cmd to find
 * @pathstr: the PATH string
 *
 * Return: full path of cmd if found and executable, otherwise NULL
 */
char *is_custom_cmd(info_t *info, char *path, char *cmd, char *pathstr)
{
    struct stat st;

    (void)info;
    if (!path || stat(path, &st))
        return (NULL);

    if (st.st_mode & S_IFREG && st.st_mode & S_IXUSR)
    {
        return (path);
    }

    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_custom_cmd(info, cmd, cmd, pathstr))
            return (cmd);
    }

    int i = 0, curr_pos = 0;
    char *full_path;

    while (1)
    {
        if (!pathstr[i] || pathstr[i] == ':')
        {
            full_path = dup_chars(pathstr, curr_pos, i);
            if (!*full_path)
                _strcat(full_path, cmd);
            else
            {
                _strcat(full_path, "/");
                _strcat(full_path, cmd);
            }
            if (is_custom_cmd(info, full_path, cmd, pathstr))
                return (full_path);
            if (!pathstr[i])
                break;
            curr_pos = i;
        }
        i++;
    }

    return (NULL);
}
