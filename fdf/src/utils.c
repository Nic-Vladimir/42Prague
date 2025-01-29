/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:24:07 by vnicoles          #+#    #+#             */
/*   Updated: 2025/01/21 20:59:38 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_put_pixel(t_fdf *env, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * env->bits_per_pixel / 8) + (y * env->size_line);
		env->data_addr[i] = color;
		env->data_addr[++i] = color >> 8;
		env->data_addr[++i] = color >> 16;
	}
}

void	ft_get_z_min_max(t_map *map, int n)
{
	if (n > map->z_max)
		map->z_max = n;
	if (n < map->z_min)
		map->z_min = n;
}

void	ft_return_error(char *err_msg, t_fdf *env)
{
	ft_printf("%s\n", err_msg);
	if (env)
		ft_close_win(env);
	exit(-1);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	free_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
}
