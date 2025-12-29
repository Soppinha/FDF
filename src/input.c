/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:30:22 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/28 17:56:31 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	checker_extension(char *filename, char *extension)
{
	char	*str;

	str = ft_strrchr(filename, '.');
	if (!str)
		return (0);
	if (ft_strcmp(str, extension) != 0)
		return (0);
	return (1);
}

static int	checker_file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	input_validation(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd(INPUT_ERROR, 2);
		return (0);
	}
	if (!checker_extension(av[1], ".fdf"))
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
