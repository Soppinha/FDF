/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:53:09 by svaladar          #+#    #+#             */
/*   Updated: 2026/01/16 20:54:00 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	expose_handle(t_fdf *fdf)
{
	render(fdf);
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == 4)
		fdf->cam->scale_factor += 2;
	else if (button == 5 && fdf->cam->scale_factor > 2)
		fdf->cam->scale_factor -= 2;
	render(fdf);
	return (0);
}

int	close_handle(t_fdf *fdf)
{
	close_all(fdf, 0);
	return (0);
}
