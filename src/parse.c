/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:30:22 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/27 20:25:29 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	checker_extesion(char *filename, char *extension)
{
	char	*str;
	int		is_equals;

	str = ft_strchr(filename, '.');
	if (!str)
		return (0);
	is_equals = ft_strcmp(str, extension);
	if (is_equals != 0)
		return (0);
	return (is_equals);
}

int	checker_file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	parse_validation(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd(INPUT_ERROR, 2);
		return (0);
	}
	if (!checker_extesion(av[1], ".fdf"))
	{
		ft_putstr_fd(EXTENSION_ERROR, 2);
		return (0);
	}
	if (!checker_file_exists(av[1]))
	{
		ft_putstr_fd(FILE_ERROR, 2);
		return (0);
	}
	return (1);
}
