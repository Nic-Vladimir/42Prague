/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:19:51 by vnicoles          #+#    #+#             */
/*   Updated: 2025/01/21 22:04:57 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_get_height(char *filename, t_fdf *env)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", env);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*line == '\0')
		{
			free(line);
			break ;
		}
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) == -1)
		ft_return_error("close error", env);
	return (height);
}

static int	ft_get_width(char *filename, t_fdf *env)
{
	int		fd;
	int		width;
	char	*line;
	int		i;

	i = -1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", env);
	width = 0;
	line = get_next_line(fd);
	if (line == NULL)
		ft_return_error("invalid map (empty)", env);
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	free(line);
	free_line(fd);
	if (close(fd) == -1)
		ft_return_error("close error", env);
	return (width);
}

static void	ft_get_z_min_max(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->z_min = map->array[0][0][0];
	map->z_max = map->array[0][0][0];
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j][0] < map->z_min)
				map->z_min = map->array[i][j][0];
			if (map->array[i][j][0] > map->z_max)
				map->z_max = map->array[i][j][0];
			j++;
		}
		i++;
	}
}

void	ft_check_map(char *filename, t_fdf *env)
{
	int		fd;
	int		i;

	env->map->width = ft_get_width(filename, env);
	env->map->height = ft_get_height(filename, env);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("map open error", env);
	i = -1;
	env->map->array = malloc(sizeof(int **) * env->map->height);
	if (!env->map->array)
		ft_return_error("map height malloc error", env);
	ft_fill_map(fd, env);
	ft_get_z_min_max(env->map);
	if (close(fd) == -1)
		ft_return_error("close error", env);
}
