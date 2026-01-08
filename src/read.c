/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:18:00 by svaladar          #+#    #+#             */
/*   Updated: 2026/01/08 19:45:39 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	get_width(char *file_name)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	width = (int)ft_count_words(line, ' ');
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		if (!validate_line_width(line, width, fd))
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (width);
}

static int	get_depth(char *file_name)
{
	int		fd;
	int		depth;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (0);
	depth = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_isprint(*line))
			depth++;
		free(line);
	}
	close(fd);
	return (depth);
}

static void	get_points(char *file_name, t_map *map)
{
	int		fd;
	char	*line;
	char	**split;
	int		coord[2];

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return ;
	coord[1] = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		coord[0] = 0;
		process_line_points(split, map, coord);
		free(split);
		free(line);
		coord[1]++;
	}
	close(fd);
}

t_map	*read_map(char *file_name)
{
	t_map	*map;
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (error(2), NULL);
	close(fd);
	map = init_map();
	if (!map)
		return (NULL);
	map->max_x = get_width(file_name);
	map->max_y = get_depth(file_name);
	if (!validate_map(map))
		return (NULL);
	map->coordinates = init_coordinates(map->max_x, map->max_y);
	if (!map->coordinates)
	{
		free(map);
		return (NULL);
	}
	get_points(file_name, map);
	center_to_origin(map);
	return (map);
}
