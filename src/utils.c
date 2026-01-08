/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:18:12 by cado-car          #+#    #+#             */
/*   Updated: 2026/01/07 22:58:00 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	absolute(float nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	should_render(t_fdf *fdf)
{
	long	current_time;
	long	delta;

	current_time = get_time_ms();
	delta = current_time - fdf->cam->last_render_time;
	if (delta >= 16)  // ~60 FPS (16ms entre frames)
	{
		fdf->cam->last_render_time = current_time;
		return (1);
	}
	return (0);
}
