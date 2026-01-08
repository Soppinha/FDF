/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:25:52 by cado-car          #+#    #+#             */
/*   Updated: 2026/01/07 23:35:23 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	expose_handle(t_fdf *fdf);

int	loop_render(t_fdf *fdf)
{
	static int	need_render = 1;
	
	if (need_render)
	{
		render(fdf);
		need_render = 0;
	}
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == 4)
		fdf->cam->scale_factor += 5;
	else if (button == 5 && fdf->cam->scale_factor > 2)
		fdf->cam->scale_factor -= 5;
	render(fdf);  // Mantém o render aqui
	return (0);
}

int	main(int argc, char **argv)
{
	char    *file_name;
    t_fdf   *fdf;

    if (argc != 2)
		error(1);
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
}

static int	expose_handle(t_fdf *fdf)
{
	render(fdf);
	return (0);
}
