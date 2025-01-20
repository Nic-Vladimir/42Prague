/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:27:02 by vnicoles          #+#    #+#             */
/*   Updated: 2025/01/20 11:54:15 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static t_fdf	*fdf_init(char *filename)
{
	t_fdf	*env;
	char	*window_title;

	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		ft_return_error("Error: t_fdf malloc failed");
	env->mlx = mlx_init();
	if (!env->mlx)
		ft_return_error("Error: mlx_init failed");
	window_title = ft_strjoin("FdF - ", filename);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, window_title);
	free(window_title);
	if (!env->win)
		ft_return_error("Error: mlx_new_window failed");
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		ft_return_error("Error: mlx_new_image failed");
	env->data_addr = mlx_get_data_addr(env->img, &env->bits_per_pixel,
									   &env->size_line, &env->endian);
	env->map = NULL;
	env->camera = NULL;
	return (env);
}

static t_camera *ft_camera_init(t_fdf *env)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		ft_return_error("Error: camera malloc failed");
	camera->zoom = ft_min(WIDTH / env->map->width / 2,
					   HEIGHT / env->map->height / 2);
		camera->x_angle = -0.615472907;
	camera->y_angle = -0.523599;
	camera->z_angle = 0.615472907;
	camera->z_height = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->iso = 1;
	return (camera);
}

static t_map	*ft_map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_return_error("Error: map malloc failed");
	map->width = 0;
	map->height = 0;
	map->array = NULL;
	map->z_min = 0;
	map->z_max = 0;
	return (map);
}

int	main(int argc, char **argv)
{
	t_fdf	*env;

	if (argc != 2)
		ft_return_error("Usage: ./fdf <path/to/map>");
	env = fdf_init(argv[1]);
	env->map = ft_map_init();
	ft_check_map(argv[1], env->map);
	env->camera = ft_camera_init(env);
	ft_hook_input(env);
	ft_draw(env->map, env);
	mlx_loop(env->mlx);
}
