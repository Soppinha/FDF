/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 21:37:28 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/21 21:37:35 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project(t_point p, t_fdf *fdf)
{
	t_point	projected;
	int		x;
	int		y;

	x = p.x;
	y = p.y;
	projected.x = (x - y) * cos(0.523599);
	projected.y = (x + y) * sin(0.523599) - p.z;
	projected.x *= fdf->zoom;
	projected.y *= fdf->zoom;
	projected.x += fdf->offset_x;
	projected.y += fdf->offset_y;
	projected.color = p.color;
	return (projected);
}