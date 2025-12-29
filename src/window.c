/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:49:01 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/29 14:27:48 by svaladar         ###   ########.fr       */
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

void	win_init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->display = get_screen_size();
	fdf->display.win = mlx_new_window(fdf->mlx,
			fdf->display.width, fdf->display.height, "FDF Window");
	mlx_hook(fdf->display.win, X_BUTTON, 0, close_win, fdf);
	mlx_key_hook(fdf->display.win, close_win_esc, fdf);
	mlx_loop(fdf->mlx);
}
