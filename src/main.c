/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:04:03 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/29 14:28:33 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (!input_validation(ac, av))
		return (1);
	fdf = init_fdf();
	if (!fdf)
	{
		ft_putstr_fd(ALLOC_ERROR, 2);
		return (1);
	}

	win_init(fdf);
	return (0);
}
