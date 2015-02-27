/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:22:19 by amaurer           #+#    #+#             */
/*   Updated: 2015/02/27 22:50:31 by nsierra-         ###   ########.fr       */
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

static void	print_game_value(char *title, uint val)
{
	ft_putstr(title);
	ft_putnbr(val);
	ft_putendl("");
}

void		print_game(t_2048 *game)
{
	print_game_value("width: ", game->width);
	print_game_value("height: ", game->height);
	print_game_value("score: ", game->score);
	print_game_value("win value: ", game->win_value);
	print_game_value("move_count: ", game->move_count);
	print_game_value("seed: ", game->seed);
	print_game_value("base: ", game->base);
}
