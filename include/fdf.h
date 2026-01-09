/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:14:12 by svaladar          #+#    #+#             */
/*   Updated: 2026/01/08 23:11:48 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "keys.h"
# include "colors.h"

# define WINDOW_NAME	 	"fdf"
# define WINDOW_WIDTH		1900
# define WINDOW_HEIGHT		1080
# define MAX_PIXEL			1080000

# define LINE_DEFAULT		C_WHITE
# define BACKGROUND_DEFAULT	C_BLACK
# define C_TEXT				C_WHITE

# define HEXADECIMAL_L_BASE	"0123456789abcdef"
# define ANG_1				0.01745329
# define ANG_30				0.52359877
# define ANG_45				0.78539816

enum e_projection
{
	ISOMETRIC,
	PERSPECTIVE,
	TOP
};

enum e_bool
{
	FALSE,
	TRUE
};

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_map
{
	t_point	**coordinates;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
}	t_map;

typedef struct s_line
{
	t_point	start;
	t_point	end;
	float	transform_z;
}	t_line;

typedef struct s_color
{
	int	start_color;
	int	start_r;
	int	start_g;
	int	start_b;
	int	end_color;
	int	end_r;
	int	end_g;
	int	end_b;
	int	delta_r;
	int	delta_g;
	int	delta_b;
}	t_color;

typedef struct s_image
{
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	t_line	*line;
}	t_image;

typedef struct s_cam
{
	int		projection;
	int		color_pallet;
	float	scale_factor;
	float	scale_z;
	float	move_x;
	float	move_y;
	double	alpha;
	double	beta;
	double	gamma;
	long	last_render_time;
}	t_cam;

typedef struct s_fdf
{
	t_map	*map;
	void	*mlx;
	int		win_x;
	int		win_y;
	void	*win;
	t_image	*image;
	t_cam	*cam;
}	t_fdf;

t_map	*read_map(char *file_name);

void	error(int exit_code);

t_fdf	*init_fdf(char *file_name);
t_map	*init_map(void);
t_image	*init_image(void *mlx, int width, int height);
t_line	*init_line(t_point start, t_point end, t_fdf *fdf);
t_cam	*init_cam(t_map *map, int win_width, int win_height);

t_point	**init_coordinates(int width, int depth);
void	center_to_origin(t_map *map);
float	scale_to_fit(t_map *map);
void	reset(t_fdf *fdf);
void	close_all(t_fdf *fdf, int exit_code);
void	close_map(t_fdf *fdf, int exit_code);
t_color	*color_init(t_point start, t_point end);
t_color	*color_pallet_init(int min_color, int max_color);

float	absolute(float nbr);
float	max(float a, float b);
float	min(float a, float b);

void	render(t_fdf *fdf);
void	bresenham(t_fdf *fdf, t_point start, t_point end);
void	pixel_to_image(t_image *image, float x, float y, int color);
void	clear_image(
			t_image *image, int image_size, int win_width, int win_height);
void	print_menu(t_fdf *fdf);
int		get_color(t_color *color, int i_line, int line_size);

void	rotate(t_cam *cam, t_line *line);
void	rotate_x(t_line *line, double angle);
void	rotate_y(t_line *line, double angle);
void	rotate_z(t_line *line, double angle);
void	project(t_cam *cam, t_line *line);
void	transform(t_cam *cam, t_line *line);
void	scale(t_line *line, int scale_factor);
void	translate(t_line *line, int move_x, int move_y);

int		key_handle(int keycode, t_fdf *fdf);
int		close_handle(t_fdf *fdf);
void	*free_allocated_coords(t_point **coordinates, int count);
t_point	*alloc_row(int depth);
void	fill_point(char *point, t_map *map, int coord_x, int coord_y);
int		validate_line_width(char *line, int expected_width, int fd);
void	process_line_points(char **split, t_map *map, int coord[2]);
int		validate_map(t_map *map);
int		expose_handle(t_fdf *fdf);
int		mouse_zoom(int button, int x, int y, t_fdf *fdf);
void	free_fdf_parts(t_fdf *fdf);
int		validate_file_access(char *file_name);

#endif