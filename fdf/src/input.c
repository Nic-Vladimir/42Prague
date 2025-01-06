/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:04:14 by vnicoles          #+#    #+#             */
/*   Updated: 2025/01/06 01:04:14 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_hook_input(t_fdf *env)
{
	mlx_hook(env->win, 2, 0, ft_key_press, env);
}

int ft_key_press(int key, void *params)
{
	t_fdf	*env;

	env = (t_fdf *)params;
	printf("Key pressed: %d\n", key);
	if (key == ESCAPE)
		ft_close_win(env);
	ft_draw(env->map, env);
	return (0);
}

int	ft_close_win(void *params)
{
	t_fdf	*env;
	int		x;
	int		y;

	env = (t_fdf *)params;
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	free(env->camera);
	y = -1;
	while (++y < env->map->height)
	{
		x = -1;
		while (++x < env->map->width)
			free(env->map->array[y][x]);
		free(env->map->array[y]);
	}
	free(env->map->array);
	free(env->map);
	free(env->mlx);
	free(env);
	exit(0);
}
