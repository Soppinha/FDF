/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 21:38:40 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/21 21:38:52 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img.img_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	free_map(fdf->map);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
		close_window(fdf);
	return (0);
}
