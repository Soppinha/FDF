/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 21:38:59 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/21 21:39:07 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_fdf(t_fdf *fdf, t_map *map)
{
	fdf->map = map;
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FDF");
	fdf->img.img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img_ptr, &fdf->img.bpp,
			&fdf->img.line_len, &fdf->img.endian);
	fdf->zoom = 20;
	fdf->offset_x = WIDTH / 2;
	fdf->offset_y = HEIGHT / 2;
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	t_map	*map;

	if (argc != 2)
		ft_error("Usage: ./fdf <map_file.fdf>");
	map = read_map(argv[1]);
	init_fdf(&fdf, map);
	draw_map(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img.img_ptr, 0, 0);
	mlx_key_hook(fdf.win_ptr, key_press, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, close_window, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}