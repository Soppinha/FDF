/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:19:56 by svaladar          #+#    #+#             */
/*   Updated: 2026/01/08 19:44:28 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	error(int exit_code)
{
	if (exit_code == 0)
		ft_putstr_fd("FDF closed. Bye!\n", 1);
	else if (exit_code == 1)
		ft_putstr_fd("Error: Wrong usage. Expected './fdf <file_path>'.\n", 2);
	else if (exit_code == 2)
		ft_putstr_fd("Error: Cannot read file.\n", 2);
	else if (exit_code == 3)
		ft_putstr_fd("Error: Cannot initialize fdf.\n", 2);
	else if (exit_code == 4)
		ft_putstr_fd("Error: Cannot parse map.\n", 2);
	else if (exit_code == 5)
		ft_putstr_fd("Error: Cannot create image.\n", 2);
	else if (exit_code == 6)
		ft_putstr_fd("Error: Cannot initialize camera.\n", 2);
	else if (exit_code == 7)
		ft_putstr_fd("Error: Unable to render.\n", 2);
	else if (exit_code == 8)
		ft_putstr_fd("Error: Unable to initialize color.\n", 2);
}
