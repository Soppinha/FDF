/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:08:40 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/28 20:37:09 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	is_line_empty(char *s)
{
	while (*s && s != '\n')
	{
		if (s[0] != ' ' && s[0] != '\t')
			return (0);
		s++;
	}
	return (1);
}

int	count_columms(char *line)
{
	int	i;
	
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

void	get_map_gimensions(char *filename, t_map *map)
{

}
