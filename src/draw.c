/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:02:49 by cado-car          #+#    #+#             */
/*   Updated: 2026/01/08 19:37:57 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	bresenham(t_fdf *fdf, t_point start, t_point end)
{
	float	x_step;
	float	y_step;
	int		max_steps;
	int		i_line;
	t_color	*color;

	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_steps = (int)max(absolute(x_step), absolute(y_step));
	x_step /= max_steps;
	y_step /= max_steps;
	color = color_init(start, end);
	if (!color)
		close_all(fdf, 8);
	i_line = 0;
	while (i_line < max_steps)
	{
		start.color = get_color(color, i_line++, max_steps);
		if (start.x > 0 && start.y > 0 && start.x < fdf->win_x
			&& start.y < fdf->win_y)
			pixel_to_image(fdf->image, start.x, start.y, start.color);
		start.x += x_step;
		start.y += y_step;
	}
	free(color);
}

void	pixel_to_image(t_image *image, float x, float y, int color)
{
	int	pixel;
	int	max_pixel;

	if (x < 0 || y < 0)
		return ;
	pixel = ((int)y * image->line_bytes) + ((int)x * 4);
	max_pixel = image->line_bytes * (int)y + image->line_bytes;
	if (pixel < 0 || pixel + 3 >= max_pixel)
		return ;
	if (image->endian == 1)
	{
		image->buffer[pixel + 0] = (color >> 24);
		image->buffer[pixel + 1] = (color >> 16) & 0xff;
		image->buffer[pixel + 2] = (color >> 8) & 0xff;
		image->buffer[pixel + 3] = (color) & 0xff;
	}
	else if (image->endian == 0)
	{
		image->buffer[pixel + 0] = (color) & 0xff;
		image->buffer[pixel + 1] = (color >> 8) & 0xff;
		image->buffer[pixel + 2] = (color >> 16) & 0xff;
		image->buffer[pixel + 3] = (color >> 24);
	}
}

void	clear_image(t_image *image, int image_size,
	int win_width, int win_height)
{
	(void)win_width;
	(void)win_height;
	ft_bzero(image->buffer, image_size);
}
