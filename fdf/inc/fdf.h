/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:02:46 by vnicoles          #+#    #+#             */
/*   Updated: 2025/01/06 17:58:38 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define WIDTH 1920
# define HEIGHT 1080
# define ESC 65307

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	reverse;
}				t_point;

typedef struct s_map
{
	int		height;
	int		width;
	int		***array;
	int		z_max;
	int		z_min;
}				t_map;

typedef struct s_camera
{
	double	x_angle;
	double	y_angle;
	double	z_angle;
	float	z_height;
	int		x_offset;
	int		y_offset;
	int		zoom;
	int		iso;
}				t_camera;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			steep;
	char		*title;
	t_map		*map;
	t_camera	*camera;
}				t_fdf;

float	ft_abs(float n);
int		ft_ipart(float n);
float	ft_fpart(float n);
float	ft_rfpart(float n);
void	ft_draw(t_map *map, t_fdf *env);
int		ft_close_win(void *params);
void	ft_hook_input(t_fdf *env);
int		ft_key_press(int key, void *params);
void	ft_draw_line(t_point s, t_point e, t_fdf *env);
void	ft_check_map(char *filename, t_map *map);
t_point ft_projection(int x, int y, t_fdf *env);
int		get_default_color(int z, t_map *map);
int		ft_min(int a, int b);
void	ft_return_error(char *err_msg);
void	get_z_min_max(t_map *map, int n);
void	ft_put_pixel(t_fdf *env, int x, int y, int color);

#endif
