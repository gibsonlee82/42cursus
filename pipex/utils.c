#include "pipex.h"

/**********************************************************************
 Resolves the full executable path for a given command using PATH.
  - cmd: Command name (e.g., "ls").
  - envp: The environment variable array.
 Return
  - Full path to executable if found, otherwise NULL.
***********************************************************************/
char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*full_path;
	int		i;

	paths = get_cmd_path_env(envp);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(path, cmd);
		free(path);
		if (access(full_path, X_OK) == 0)
			return (free_split(paths), full_path);
		free(full_path);
		i++;
	}
	free_split(paths);
	return (NULL);
}

/**********************************************************************
 Extracts and splits the PATH environment variable into directories.
  - envp: The environment variable array.
 Return:
  - A NULL-terminated array of directory strings,
    or NULL if PATH is not found or on allocation failure.
***********************************************************************/
char	**get_cmd_path_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

/**********************************************************************
frees a null-terminated array of strings.
- arr: the array of strings to free (e.g., result from ft_split).

this function iterates through a dynamically allocated array of strings,
freeing each individual string and then the array itself.
It safely handles a NULL pointer by checking before accessing elements.
**********************************************************************/
void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
}

// void	free_split_exit(char **arr, int exit_code)
// {
// 	free_split(arr);
//     exit(exit_code);
// }

/**********************************************************************
Prints an error message and exits the program.
- text: The error message to display.
- exit_code: The exit status to return when exiting the program.

This function writes the given error message to standard error (fd = 2)
and immediately exits the program with the provided exit code.
**********************************************************************/

void	error_exit(char *text, int exit_code)
{
	write(2, text, ft_strlen(text));
	exit(exit_code);
}

/**********************************************************************
 Frees a dynamically allocated array of strings and exits the program.
  - arr:      A NULL-terminated array of strings to free.
  - text:     Optional error message to display before exiting.
  - exit_code: Exit status code to return from the program.
 Behavior:
  - Frees all memory in 'arr' using free_split().
  - If 'text' is not NULL and not empty, prints it to stderr using error_exit().
  - Otherwise, exits directly with the provided exit_code.
 **********************************************************************/
void    free_split_error_exit(char **arr, char *text, int exit_code)
{
    	free_split(arr);
        if (text != NULL && *text != '\0')
            error_exit(text, exit_code);
        else
            exit(exit_code);
}