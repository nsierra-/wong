/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:22:19 by amaurer           #+#    #+#             */
/*   Updated: 2015/03/01 01:49:40 by amaurer          ###   ########.fr       */
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
	int	x;
	int	y;

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
	ft_putchar('\n');
}

int			ft_nbrlen(int n)
{
	size_t	i;

	if (!n)
		return (1);
	i = (n < 0) ? 1 : 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}
