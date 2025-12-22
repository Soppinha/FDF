/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:10:38 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/22 17:04:44 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080
# define ESC_KEY 65307

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	int		**z_matrix;
	int		**color_matrix;
}	t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	*map;
	int		zoom;
	int		offset_x;
	int		offset_y;
}	t_fdf;

/* Parse */
t_map	*read_map(char *filename);
void	free_map(t_map *map);

/* Draw */
void	draw_line(t_fdf *fdf, t_point p1, t_point p2);
void	draw_map(t_fdf *fdf);

/* Projection */
t_point	project(t_point p, t_fdf *fdf);

/* Events */
int		key_press(int keycode, t_fdf *fdf);
int		close_window(t_fdf *fdf);

/* Utils */
int		ft_atoi(const char *str);
void	ft_error(char *msg);

#endif