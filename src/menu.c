/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:52:04 by svaladar          #+#    #+#             */
/*   Updated: 2026/01/08 17:52:45 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char	*get_projection_name(t_fdf *fdf)
{
	char	*projection;

	projection = "";
	if (fdf->cam->projection == ISOMETRIC)
		projection = "Isometric projection";
	else if (fdf->cam->projection == PERSPECTIVE)
		projection = "Perspective projection";
	else if (fdf->cam->projection == TOP)
		projection = "Top view";
	return (projection);
}

void	print_menu(t_fdf *fdf)
{
	int		y;
	char	*projection;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	projection = get_projection_name(fdf);
	mlx_string_put(mlx, win, 50, y += 60, C_TEXT, projection);
	mlx_string_put(mlx, win, 50, y += 45, C_TEXT, "Press 'ESC' to close");
	mlx_string_put(mlx, win, 50, y += 45, C_TEXT, "Zoom: scroll or '-' '+'");
	mlx_string_put(mlx, win, 50, y += 30, C_TEXT, "Move: arrow keys");
	mlx_string_put(mlx, win, 50, y += 30, C_TEXT, "Rotate X: 'S' or 'W'");
	mlx_string_put(mlx, win, 50, y += 30, C_TEXT, "Rotate Y: 'Q' or 'E'");
	mlx_string_put(mlx, win, 50, y += 30, C_TEXT, "Rotate Z: 'A' or 'D'");
	mlx_string_put(mlx, win, 50, y += 30, C_TEXT, "Scale Z: 'Z' or 'X'");
	mlx_string_put(mlx, win, 50, y += 30, C_TEXT, "(Z limited to 100%)");
	mlx_string_put(mlx, win, 50, y += 45, C_TEXT, "Change projection:");
	mlx_string_put(mlx, win, 50, y += 30, C_TEXT, "Isometric: 'I'");
	mlx_string_put(mlx, win, 50, y += 30, C_TEXT, "Perspective: 'P'");
	mlx_string_put(mlx, win, 50, y += 30, C_TEXT, "Top View: 'O'");
	mlx_string_put(mlx, win, 50, y += 45, C_TEXT, "Colors: 'SPACE'");
	mlx_string_put(mlx, win, 50, y += 45, C_TEXT, "Reset: 'R'");
}
