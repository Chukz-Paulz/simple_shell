#include "shell.h"

/**
 * is_cmd - This determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	/*Declarations*/
	struct stat st;

	(void)info;
	return (path && !stat(path, &st) && (st.st_mode & S_IFREG));
}

/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	/*Declaration*/
	static char buf[1024];
	int i, k;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = '\0';
	return (buf);
}

/**
 * find_path - This finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	/*Declaration*/
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);

	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
		return (is_cmd(info, cmd) ? cmd : NULL);

	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
				_strcat(path, "/");
			_strcat(path, cmd);

			if (is_cmd(info, path))
				return (path);

			if (!pathstr[i])
				break;

			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
