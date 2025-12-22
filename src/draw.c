/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 21:25:04 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/21 21:38:17 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = fdf->img.addr
			+ (y * fdf->img.line_len + x * (fdf->img.bpp / 8));
		*(int *)pixel = color;
	}
}

static float	ft_abs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	float	x_step;
	float	y_step;
	int		max;
	float	x;
	float	y;

	x = p1.x;
	y = p1.y;
	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - p2.x) || (int)(y - p2.y))
	{
		put_pixel(fdf, x, y, 0xFFFFFF);
		x += x_step;
		y += y_step;
	}
}

void	draw_map(t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			p1.x = x;
			p1.y = y;
			p1.z = fdf->map->z_matrix[y][x];
			if (x < fdf->map->width - 1)
			{
				p2.x = x + 1;
				p2.y = y;
				p2.z = fdf->map->z_matrix[y][x + 1];
				draw_line(fdf, project(p1, fdf), project(p2, fdf));
			}
			if (y < fdf->map->height - 1)
			{
				p2.x = x;
				p2.y = y + 1;
				p2.z = fdf->map->z_matrix[y + 1][x];
				draw_line(fdf, project(p1, fdf), project(p2, fdf));
			}
			x++;
		}
		y++;
	}
}
