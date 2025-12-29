/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:35:45 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/29 17:19:54 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	parse_color(char *str)
{
	int		color;
	char	*hex;

	hex = ft_strchr(str, ',');
	if (!hex)
		return (0xFFFFFF);
	hex++;
	color = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		hex += 2;
	return (color);
}

int	parse_line(char *line, t_map *map, int y)
{
	char	**values;
	int		x;

	values = ft_split(line, ' ');
	if (!values)
		return (0);
	
}

