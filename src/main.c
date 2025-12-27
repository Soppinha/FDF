/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:04:03 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/26 22:07:51 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_win(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	Display *display;
    Screen  *screen;
    int     width;
    int     height;

	display = XOpenDisplay(NULL);
    if (!display)
    {
        return (1);
    }
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	{
		write(1, "Erro no mlx_init\n", 17);
		return (1);
	}
	screen = DefaultScreenOfDisplay(display);
	width = screen->width;
	height = screen->height;
	win_ptr = mlx_new_window(mlx_ptr, width, height, "FdF");
	if (!win_ptr)
	{
		write(1, "Erro no mlx_new_window\n", 23);
		return (1);
	}
	mlx_key_hook(win_ptr, close_win, NULL);
	mlx_loop(mlx_ptr);
	XCloseDisplay(display);
	return (0);
}
