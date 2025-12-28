/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:49:01 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/27 20:52:19 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_win(int keycode, void *param)
{
	(void)param;
	if (keycode == ESC_KEY)
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
