/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:37:19 by svaladar          #+#    #+#             */
/*   Updated: 2026/01/08 19:40:04 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	validate_line_width(char *line, int expected_width, int fd)
{
	int	new_width;

	new_width = (int)ft_count_words(line, ' ');
	if (expected_width != new_width)
	{
		free(line);
		close(fd);
		return (0);
	}
	return (1);
}

void	process_line_points(char **split, t_map *map, int coord[2])
{
	coord[0] = 0;
	while (coord[0] < map->max_x)
	{
		fill_point(split[coord[0]], map, coord[0], coord[1]);
		free(split[coord[0]]);
		coord[0]++;
	}
}

void	parse_point_color(char *point, t_map *map, int x, int y)
{
	char	**info;
	int		i;

	info = ft_split(point, ',');
	map->coordinates[x][y].z = (float)ft_atoi(info[0]);
	map->coordinates[x][y].color = ft_atoi_base(info[1], HEXADECIMAL_L_BASE);
	i = 0;
	while (info[i])
		free(info[i++]);
	free(info);
}

int	validate_map(t_map *map)
{
	if (map->max_x == 0 || map->max_y == 0)
		return (free(map), 0);
	return (1);
}
