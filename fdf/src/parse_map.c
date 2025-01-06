/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:19:51 by vnicoles          #+#    #+#             */
/*   Updated: 2024/12/09 13:23:19 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_height(char *filename)
{
    int     fd;
    int     height;
    char    *line;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        ft_return_error("open error", 1);
    height = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (*line == '\0')  // Empty line check
        {
            free(line);
            break;
        }
        height++;
        free(line);
    }
    if (close(fd) == -1)
        ft_return_error("close error", 1);
    return (height);
}

static int ft_get_width(char *filename)
{
    int     fd;
    int     width;
    char    *line;
    int     i;

    i = -1;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        ft_return_error("open error", 1);
    width = 0;
    if ((line = get_next_line(fd)) == NULL)
        ft_return_error("invalid map (empty)", 0);
    // Count width by counting numbers in first line
    while (line[++i])
        if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
            width++;
    free(line);
    // Read and free remaining lines
    while ((line = get_next_line(fd)) != NULL)
        free(line);

    if (close(fd) == -1)
        ft_return_error("close error", 1);
    return (width);
}

static void	ft_fill_table(int **n, char *line, int width)
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
			ft_return_error("malloc error", 1);
		n[i][0] = ft_atoi(num[i]);
		j = 0;
		while (num[i][j] && num[i][j] != ',')
			j++;
		if (num[i][j] == ',')
			n[i][1] = (strtol(&num[i][++j], NULL, 16));
		else
			n[i][1] = -1;
		free(num[i]);
	}
	if (i != width || num[i])
		ft_return_error("error: fdf file has irregular width", 0);
	free(num);
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

void	ft_check_map(char *filename, t_map *map)
{
   int		fd;
   char		*line;
   int		i;

	map->width = ft_get_width(filename);
	map->height = ft_get_height(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("map open error", 1);
	i = -1;
	map->array = malloc(sizeof(int **) * map->height);
	if (!map->array)
		ft_return_error("map height malloc error", 1);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (*line == '\0')
		{
			free(line);
			break;
		}
		map->array[++i] = malloc(sizeof(int *) * map->width);
		if (!map->array[i])
			ft_return_error("map width malloc error", 1);
		ft_fill_table(map->array[i], line, map->width);
		free(line);
	}
	ft_get_z_min_max(map);
	if (close(fd) == -1)
		ft_return_error("close error", 1);
}

