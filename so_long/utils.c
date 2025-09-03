/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:00:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/29 11:13:10 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	error_exit(char *msg, t_game *g)
{
	write(2, "Error\n", 6);
	if (msg)
		write(2, msg, ft_strlen(msg));
	(void) close_game(g);
	exit(1);
}

static char	*join_and_free(char *s1, const char *s2, size_t len, t_game *g)
{
	char	*sub;
	char	*res;

	sub = ft_substr(s2, 0, len);
	res = ft_strjoin(s1, sub);
	free(s1);
	free(sub);
	if (!res)
		error_exit("malloc\n", g);
	return (res);
}

char	*sl_read_all(int fd, t_game *g)
{
	char	buf[1024];
	char	*out;
	ssize_t	r;

	ft_bzero(buf, 1024);
	out = ft_strdup("");
	if (!out)
		error_exit("malloc\n", g);
	r = read(fd, buf, sizeof(buf));
	while (r > 0)
	{
		out = join_and_free(out, buf, (size_t)r, g);
		r = read(fd, buf, sizeof(buf));
	}
	if (r < 0)
		error_exit("read\n", g);
	return (out);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
	map = NULL;
}
