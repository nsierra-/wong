/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:38:17 by nsierra-          #+#    #+#             */
/*   Updated: 2015/02/28 00:02:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "wong.h"

static int	get_number_size(uint num)
{
	int		ret;

	ret = 0;
	while (num > 0)
	{
		num /= 10;
		++ret;
	}
	return (ret);
}

void		get_max_case_size(t_2048 *game, t_draw_infos *infos)
{
	infos->max_case_width = COLS / game->width;
	if (LINES > 1)
		infos->max_case_height = (LINES - 1) / game->height;
	else
		infos->max_case_height = 0;
}

void		get_max_number_size(t_2048 *game)
{
	uint	x;
	uint	y;
	int		tmp;
	int		ret;

	y = 0;
	ret = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			tmp = get_number_size(game->map[y][x]);
			ret = tmp > ret ? tmp : ret;
			x++;
		}
		y++;
	}
}
