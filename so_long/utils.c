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

void	error_exit(char *msg)
{
	write(2, "Error\n", 6);
	if (msg)
		write(2, msg, ft_strlen(msg));
	exit(1);
}

/* read whole file with read(2) only, return NUL-terminated heap string */
char	*sl_read_all(int fd)
{
	char	buf[1024];
	char	*out;
	char	*tmp;
	ssize_t	r;
	size_t	len;

	out = ft_strdup("");
	if (!out)
		error_exit("malloc\n");
	r = read(fd, buf, sizeof(buf));
	while (r > 0)
	{
		tmp = out;
		len = (size_t)r;
		out = ft_strjoin(tmp, ft_substr(buf, 0, len));
		free(tmp);
		if (!out)
			error_exit("malloc\n");
		r = read(fd, buf, sizeof(buf));
	}
	if (r < 0)
		error_exit("read\n");
	return (out);
}

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

int	handle_resize(t_game *g)
{
	if (!g || !g->mlx || !g->win)
		return (0);
	mlx_clear_window(g->mlx, g->win);
	render_map(g);
	return (0);
}

