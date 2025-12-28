/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:31:10 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/27 21:02:22 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf	*init_fdf(void)
{
	t_fdf	*win_fdf;

	win_fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!win_fdf)
		return (NULL);
	win_fdf->mlx = NULL;
	win_fdf->display = (t_screen){0};
	win_fdf->map = NULL;
	win_fdf->zoom = 20;
	win_fdf->offset_x = 100;
	win_fdf->offset_y = 100;
	win_fdf->angle_x = 0.523599;
	win_fdf->angle_y = 0.523599;
	win_fdf->angle_z = 0.785398;
	return (win_fdf);
}
