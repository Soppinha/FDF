/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:57:33 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/29 14:31:07 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	read_map(char *filename, t_fdf *fdf)
{
	char	*buffer;

	if (!filename)
		return (0);
	if (!fdf)
		return (0);
	buffer = malloc(sizeof(int));
	return (1);
}
