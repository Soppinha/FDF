/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 22:17:05 by svaladar          #+#    #+#             */
/*   Updated: 2026/01/08 22:17:59 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	init_fdf_map(t_fdf *fdf, char *file_name)
{
	fdf->map = read_map(file_name);
	if (!fdf->map)
	{
		free(fdf);
		return (0);
	}
	return (1);
}

static int	init_fdf_mlx(t_fdf *fdf)
{
	int	screen_width;
	int	screen_height;

	fdf->mlx = mlx_init();
	if (!fdf->mlx)
	{
		free(fdf->map);
		free(fdf);
		error(3);
		return (0);
	}
	mlx_get_screen_size(fdf->mlx, &screen_width, &screen_height);
	fdf->win_x = screen_width;
	fdf->win_y = screen_height;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, WINDOW_NAME);
	return (1);
}

static int	init_fdf_graphics(t_fdf *fdf)
{
	if (!init_fdf_mlx(fdf))
		return (0);
	fdf->image = init_image(fdf->mlx, fdf->win_x, fdf->win_y);
	if (!fdf->image)
	{
		close_map(fdf, 5);
		return (0);
	}
	fdf->cam = init_cam(fdf->map, fdf->win_x, fdf->win_y);
	if (!fdf->cam)
	{
		close_all(fdf, 6);
		return (0);
	}
	return (1);
}

t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
	{
		error(3);
		return (NULL);
	}
	if (!init_fdf_map(fdf, file_name))
		return (NULL);
	if (!init_fdf_graphics(fdf))
		return (NULL);
	return (fdf);
}
