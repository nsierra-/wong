/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:22:19 by amaurer           #+#    #+#             */
/*   Updated: 2015/02/27 21:39:33 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <wong.h>

int        return_error(int error_code)
{
    if (error_code == R_E_MALLOC)
        ft_putendl("Malloc error");
    return (error_code);
}

void		print_map(t_2048 *game)
{
	uint	x;
	uint	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			ft_putnbr(game->map[y][x]);
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}