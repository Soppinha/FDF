/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:37:19 by svaladar          #+#    #+#             */
/*   Updated: 2026/01/08 22:05:55 by svaladar         ###   ########.fr       */
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

int	validate_map(t_map *map)
{
	if (map->max_x == 0 || map->max_y == 0)
		return (free(map), 0);
	return (1);
}

int	validate_file_extension(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 4)
		return (0);
	if (ft_strncmp(file_name + len - 4, ".fdf", 4) != 0)
		return (0);
	return (1);
}

int	validate_file_access(char *file_name)
{
	int	fd;

	if (!validate_file_extension(file_name))
	{
		ft_putstr_fd("Error: File must have .fdf extension.\n", 2);
		return (0);
	}
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		error(2);
		return (0);
	}
	close(fd);
	return (1);
}
