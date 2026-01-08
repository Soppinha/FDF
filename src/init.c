/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:36:24 by cado-car          #+#    #+#             */
/*   Updated: 2026/01/07 23:27:49 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;
	int		screen_width;
	int		screen_height;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		error(3);
	fdf->map = read_map(file_name);
	if (!fdf->map)
	{
		free(fdf);
		error(4);
	}
	fdf->mlx = mlx_init();
	mlx_get_screen_size(fdf->mlx, &screen_width, &screen_height);
	fdf->win_x = screen_width;
	fdf->win_y = screen_height;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, WINDOW_NAME);
	fdf->image = init_image(fdf->mlx, fdf->win_x, fdf->win_y);
	if (!fdf->image)
		close_map(fdf, 5);
	fdf->cam = init_cam(fdf->map, fdf->win_x, fdf->win_y);
	if (!fdf->cam)
		close_all(fdf, 6);
	return (fdf);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->coordinates = NULL;
	map->max_x = 0;
	map->max_y = 0;
	map->max_z = 0;
	map->min_z = 0;
	return (map);
}

t_image	*init_image(void *mlx, int width, int height)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->image = mlx_new_image(mlx, width, height);
	image->buffer = mlx_get_data_addr(image->image, &image->pixel_bits, \
			&image->line_bytes, &image->endian);
	image->line = NULL;
	return (image);
}

t_cam	*init_cam(t_map *map, int win_width, int win_height)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->projection = ISOMETRIC;
	cam->color_pallet = FALSE;
	cam->scale_factor = scale_to_fit(map, win_width, win_height);
	cam->scale_z = 1;
	cam->move_x = win_width / 2;
	cam->move_y = win_height / 2;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->last_render_time = 0;
	return (cam);
}

t_line	*init_line(t_point start, t_point end, t_fdf *fdf)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z;
	line->start.color = start.color;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z;
	line->end.color = end.color;
	line->transform_z = max((fdf->map->max_z - fdf->map->min_z), \
		max(fdf->map->max_x, fdf->map->max_y));
	return (line);
}
