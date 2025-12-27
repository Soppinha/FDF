/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:10:38 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/26 21:56:41 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/Xlib.h>

# define WIDTH 1920
# define HEIGHT 1080
# define ESC_KEY 65307

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	int		**z_matrix;
	int		**color_matrix;
}	t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	*map;
	int		zoom;
	int		offset_x;
	int		offset_y;
}	t_fdf;

#endif