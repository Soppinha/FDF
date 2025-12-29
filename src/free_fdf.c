/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:33:14 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/28 17:49:28 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_map(t_fdf *fdf)
{
	int	i;

	if (fdf->map->z_scale)
	{
		i = 0;
		while (i < fdf->map->height)
		{
			free(fdf->map->z_scale[i]);
			i++;
		}
		free(fdf->map->z_scale);
	}
	if (fdf->map->color)
	{
		i = 0;
		while (i < fdf->map->height)
		{
			free(fdf->map->color[i]);
			i++;
		}
		free(fdf->map->color);
	}
	free(fdf->map);
}

void	free_fdf(t_fdf *fdf)
{
	if (!fdf)
		return ;
	if (fdf->map)
		free_map(fdf);
	free(fdf);
}
