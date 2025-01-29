/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:04:14 by vnicoles          #+#    #+#             */
/*   Updated: 2025/01/21 23:56:47 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_hook_input(t_fdf *env)
{
	mlx_key_hook(env->win, ft_key_press, env);
	mlx_hook(env->win, 17, 0, ft_close_win, env);
}

int	ft_key_press(int key, void *params)
{
	t_fdf	*env;

	env = (t_fdf *)params;
	if (key == ESC)
		ft_close_win(env);
	ft_draw(env->map, env);
	return (0);
}

static void	ft_free_map(t_map *map)
{
	int	y;
	int	x;

	if (!map)
		return ;
	if (map->array)
	{
		y = -1;
		while (++y < map->height)
		{
			if (map->array[y])
			{
				x = -1;
				while (++x < map->width)
				{
					if (map->array[y][x])
						free(map->array[y][x]);
				}
				free(map->array[y]);
			}
		}
		free(map->array);
	}
	free(map);
}

int	ft_close_win(void *params)
{
	t_fdf	*env;

	if (!params)
		return (1);
	env = (t_fdf *)params;
	if (env->mlx)
	{
		if (env->img)
			mlx_destroy_image(env->mlx, env->img);
		if (env->win)
			mlx_destroy_window(env->mlx, env->win);
		mlx_destroy_display(env->mlx);
	}
	if (env->camera)
		free(env->camera);
	ft_free_map(env->map);
	if (env->mlx)
		free(env->mlx);
	free(env);
	exit(0);
}

// int	ft_close_win(void *params)
//{
//	t_fdf	*env;
//	int		x;
//	int		y;
//
//	env = (t_fdf *)params;
//	mlx_destroy_image(env->mlx, env->img);
//	mlx_destroy_window(env->mlx, env->win);
//	mlx_destroy_display(env->mlx);
//	free(env->camera);
//	y = -1;
//	while (++y < env->map->height)
//	{
//		x = -1;
//		while (++x < env->map->width)
//			free(env->map->array[y][x]);
//		free(env->map->array[y]);
//	}
//	free(env->map->array);
//	free(env->map);
//	free(env->mlx);
//	free(env);
//	exit(0);
//}
