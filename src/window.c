/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:49:01 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/28 17:49:47 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_win_esc(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
		close_win(fdf);
	return (0);
}

int	close_win(t_fdf *fdf)
{
	if (!fdf)
		exit(0);
	if (fdf->display.win)
		mlx_destroy_window(fdf->mlx, fdf->display.win);
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	free_fdf(fdf);
	exit(0);
	return (0);
}

t_screen	get_screen_size(void)
{
	t_screen	screen;
	Display		*display;

	display = XOpenDisplay(NULL);
	if (display)
	{
		screen.width = DisplayWidth(display, DefaultScreen(display));
		screen.height = DisplayHeight(display, DefaultScreen(display));
		XCloseDisplay(display);
	}
	else
	{
		screen.width = WIDTH;
		screen.height = HEIGHT;
	}
	return (screen);
}
// void	win_init(void)
// {
// 	t_fdf		win_fdf;
// 	t_screen	display;

// 	win_fdf.mlx = mlx_init();
// 	display = get_screen_size();
// 	display.win = mlx_new_window(win_fdf.mlx,
// 			display.width, display.height, "FDF Window");

// 	mlx_key_hook(display.win, close_win, NULL);
// 	mlx_loop(win_fdf.mlx);
// }
