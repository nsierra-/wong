/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:45:19 by amaurer           #+#    #+#             */
/*   Updated: 2015/02/28 23:35:28 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>
#include <libft.h>
#include <stdio.h>

static int		next_number_index(t_2048 *game, int x, int y)
{
	while (y < game->height)
	{
		if (game->map[y][x] != 0)
			return (y);
		y++;
	}

	return (-1);
}

static int	slide_line_0(t_2048 *game, int x, int y)
{
	int	result;

	result = next_number_index(game, x, y + 1);

	if (result == -1)
		return (-1);

	game->map[y][x] = game->map[result][x];
	game->map[result][x] = 0;

	return (slide_line_up(game, x, y));
}

static int	slide_line_1(t_2048 *game, int x, int y)
{
	int	result;

	result = next_number_index(game, x, y + 1);

	if (result == -1)
		return (-1);
	if (game->map[result][x] == game->map[y][x])
	{
		game->map[y][x] += game->map[result][x];
		game->map[result][x] = 0;
	}
	else
	{
		game->map[y + 1][x] = game->map[result][x];

		if (y + 1 != result)
			game->map[result][x] = 0;
	}

	return (slide_line_up(game, x, y + 1));
}

int		slide_line_up(t_2048 *game, int x, int y)
{
	if (y >= game->height)
		return (-1);

	if (game->map[y][x] == 0)
		return slide_line_0(game, x, y);
	else
		return slide_line_1(game, x, y);

}

void		move_up(t_2048 *game)
{
	int	x;

	x = 0;
	exit(0);
	while (x < game->height)
	{
		slide_line_up(game, x, 0);
		x++;
	}
}