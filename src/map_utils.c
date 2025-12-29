/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:08:40 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/29 15:16:56 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	is_line_empty(char *s)
{
	while (*s && *s != '\n')
	{
		if (*s != ' ' && *s != '\t')
			return (0);
		s++;
	}
	return (1);
}

int	count_columns(char *line)
{
	int		count_column;
	char	**column;

	if (!line)
		return (0);
	column = ft_split(line, ' ');
	if (!column)
		return (0);
	count_column = 0;
	while (column[count_column])
	{
		free(column[count_column]);
		count_column++;
	}
	free(column);
	return (count_column);
}

int	count_lines(char *filename)
{
	char	*line;
	int		fd;
	int		count_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!is_line_empty(line))
			count_line++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count_line);
}

int	get_map_gimensions(char *filename, t_map *map)
{
	int		fd;
	char	*line;

	map->height = count_lines(filename);
	if (map->height <= 0)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	map->width = count_columns(line);
	free(line);
	close(fd);
	if (map->width <= 0)
		return (0);
	return (1);
}
