/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:23:23 by vnicoles          #+#    #+#             */
/*   Updated: 2025/01/21 23:56:16 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// Draw a line between two points
void	ft_draw(t_map *map, t_fdf *env)
{
	int	x;
	int	y;

	ft_bzero(env->data_addr, WIDTH * HEIGHT * (env->bits_per_pixel / 8));
	y = 0;
	if (env->camera->x_angle > 0)
		y = map->height - 1;
	while (y < map->height && y >= 0)
	{
		x = 0;
		if (env->camera->y_angle > 0)
			x = map->width - 1;
		while (x < map->width && x >= 0)
		{
			if (x != map->width - 1)
				ft_draw_line(ft_projection(x, y, env), ft_projection(x + 1, y,
						env), env);
			if (y != map->height - 1)
				ft_draw_line(ft_projection(x, y, env), ft_projection(x, y + 1,
						env), env);
			x += -2 * (env->camera->y_angle > 0) + 1;
		}
		y += -2 * (env->camera->x_angle > 0) + 1;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

static void	ft_free_num(char **num)
{
	int	i;

	i = -1;
	while (num[++i])
		free(num[i]);
	free(num);
}

static int	ft_fill_table(int **n, char *line, int width, t_fdf *env)
{
	char	**num;
	int		i;
	int		j;

	num = ft_split(line, ' ');
	i = -1;
	while (num[++i] && i < width)
	{
		n[i] = malloc(sizeof(int) * 2);
		if (!n[i])
			ft_return_error("malloc error", env);
		n[i][0] = ft_atoi(num[i]);
		j = 0;
		while (num[i][j] && num[i][j] != ',')
			j++;
		if (num[i][j] == ',')
			n[i][1] = (strtol(&num[i][++j], NULL, 16));
		else
			n[i][1] = -1;
	}
	if (i != width || num[i])
		return (ft_free_num(num), 1);
	ft_free_num(num);
	return (0);
}

void	ft_fill_map(int fd, t_fdf *env)
{
	char	*line;
	int		i;
	int		problem;

	problem = 0;
	i = -1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*line == '\0')
		{
			free(line);
			break ;
		}
		env->map->array[++i] = malloc(sizeof(int *) * env->map->width);
		if (!env->map->array[i])
			ft_return_error("map width malloc error", env);
		problem += ft_fill_table(env->map->array[i], line, env->map->width,
				env);
		free(line);
		line = get_next_line(fd);
	}
	if (problem)
		ft_return_error("error: fdf file has irregular width", env);
}
