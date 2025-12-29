/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:04:03 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/28 17:55:25 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (!input_validation(ac, av))
		return (1);
	fdf = init_fdf();
	if (!fdf)
	{
		ft_putstr_fd(ALLOC_ERROR, 2);
		return (1);
	}

	fdf->mlx = mlx_init();
	fdf->display = get_screen_size();
	fdf->display.win = mlx_new_window(fdf->mlx,
			fdf->display.width, fdf->display.height, "FDF Window");
	mlx_hook(fdf->display.win, X_BUTTON, 0, close_win, fdf);
	mlx_key_hook(fdf->display.win, close_win_esc, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
