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

static char *join_and_free(char *s1, const char *s2, size_t len)
{
    char *sub = ft_substr(s2, 0, len);
    char *res = ft_strjoin(s1, sub);
    free(s1);
    free(sub);
    if (!res)
        error_exit("malloc\n");
    return (res);
}

char *sl_read_all(int fd)
{
    char buf[1024];
    char *out;
    ssize_t r;
	
	ft_bzero(buf, 1024);
	out = ft_strdup("");
    if (!out)
        error_exit("malloc\n");
    r = read(fd, buf, sizeof(buf));
    while (r > 0)
    {
        out = join_and_free(out, buf, (size_t)r);
        r = read(fd, buf, sizeof(buf));
    }
    if (r < 0)
        error_exit("read\n");
    return (out);
}

// void	free_map(char **map, int height)
// {
// 	int	i;

// 	if (!map)
// 		return ;
// 	i = 0;
// 	while (i < height)
// 	{
// 		if (map[i])
// 			free(map[i]);
// 		i++;
// 	}
// 	free(map);
// }
void free_map(char **map)
{
    int	i;

	i = 0;
    if (!map) return;
    while (map[i])
        free(map[i++]);
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
