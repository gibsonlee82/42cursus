/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:48:33 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 12:05:50 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// check if string s has newline
int	ft_has_newline(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// extract line, up to '\n' or eof
char	*ft_get_line(char *s)
{
	int		i;
	int		j;
	char	*line;

	if (!s[0])
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = ft_calloc(sizeof(char), i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = s[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

// save the remaining char, after getting nextline
char	*ft_get_remain(char *s)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	i++;
	result = ft_calloc(sizeof(char), ft_strlen(s) - i + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (s[i])
		result[j++] = s[i++];
	result[j] = '\0';
	free(s);
	return (result);
}

char	*get_data(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;

	bytes_read = 1;
	while (!ft_has_newline(stash) && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (NULL);
		stash = ft_strnjoin(stash, buffer, bytes_read);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*next;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_data(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	next = ft_get_remain(stash);
	stash = next;
	return (line);
}
