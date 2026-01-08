/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:25:52 by cado-car          #+#    #+#             */
/*   Updated: 2026/01/08 18:28:40 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	char	*file_name;
	t_fdf	*fdf;

	if (argc != 2)
	{
		error(1);
		return (1);
	}
	file_name = argv[1];
	fdf = init_fdf(file_name);
	if (!fdf)
	{
		ft_putstr_fd("Error: Failed to initialize FDF\n", 2);
		return (1);
	}
	render(fdf);
	mlx_hook(fdf->win, 17, 0, close_handle, fdf);
	mlx_key_hook(fdf->win, &key_handle, fdf);
	mlx_mouse_hook(fdf->win, &mouse_zoom, fdf);
	mlx_expose_hook(fdf->win, &expose_handle, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
