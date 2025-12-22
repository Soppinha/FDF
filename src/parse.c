/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:23:01 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/21 21:24:48 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words(char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\n' && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if ((*str == ' ' || *str == '\n') && in_word)
			in_word = 0;
		str++;
	}
	return (count);
}

static int	get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error: Cannot open file");
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

t_map	*read_map(char *filename)
{
	t_map	*map;
	int		fd;
	char	*line;
	int		i;

	map = (t_map *)malloc(sizeof(t_map));
	map->height = get_height(filename);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	map->width = count_words(line);
	map->z_matrix = (int **)malloc(sizeof(int *) * map->height);
	i = 0;
	while (line)
	{
		map->z_matrix[i] = (int *)malloc(sizeof(int) * map->width);
		fill_matrix(map->z_matrix[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}
