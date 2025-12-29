/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:10:38 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/29 15:25:17 by svaladar         ###   ########.fr       */
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
# define X_BUTTON 17
# define INPUT_ERROR "Usage: ./fdf <map_file.fdf>\n"
# define EXTENSION_ERROR "Error: Invalid file extension\n"
# define FILE_ERROR "Error: Cannot open file\n"
# define MAP_ERROR "Error: Invalid map\n"
# define ALLOC_ERROR "Error: Memory allocation failed\n"

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
	int		**z_scale;
	int		**color;
}	t_map;

// typedef struct s_img
// {
// 	void	*img_ptr;
// 	char	*addr;
// 	int		bpp;
// 	int		line_len;
// 	int		endian;
// }	t_img;

typedef struct s_screen
{
	void	*win;
	int		width;
	int		height;
}	t_screen;

typedef struct s_fdf
{
	void		*mlx;
	t_screen	display;
	t_map		*map;
	int			zoom;
	int			offset_x;
	int			offset_y;
	double		angle_x;
	double		angle_y;
	double		angle_z;
}	t_fdf;

void		win_init(t_fdf *fdf);
t_screen	get_screen_size(void);
int			close_win_esc(int keycode, t_fdf *fdf);
int			close_win(t_fdf *fdf);
t_fdf		*init_fdf(void);
void		free_fdf(t_fdf *fdf);
int			input_validation(int ac, char **av);

#endif