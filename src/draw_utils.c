/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:38:17 by nsierra-          #+#    #+#             */
/*   Updated: 2015/02/28 22:50:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "libft.h"
#include "wong.h"

int	get_number_size(int num)
{
	int		ret;

	ret = 1;
	while (num > 0)
	{
		num /= 10;
		++ret;
	}
	return (ret);
}

void		set_max_case_size(t_2048 *game, t_draw_infos *infos)
{
	infos->max_case_width = COLS / game->width;
	if (LINES > 1)
		infos->max_case_height = (LINES - 1) / game->height;
	else
		infos->max_case_height = 0;
}

void		set_max_number_size(t_2048 *game, t_draw_infos *infos)
{
	int	x;
	int	y;
	int		tmp;

	y = 0;
	infos->max_number_size = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			tmp = get_number_size(game->map[y][x]);
			infos->max_number_size = tmp > infos->max_number_size ? tmp : infos->max_number_size;
			x++;
		}
		y++;
	}
	infos->max_number_size = 1;
}

void		set_case_spaces(t_2048 *game, t_draw_infos *infos)
{
	(void)game;
	infos->case_hspace = (infos->max_case_width - infos->max_number_size - 2) / 2;
	infos->case_vspace = (infos->max_case_height - 3) / 2;
}

/*

(MAX - 1 - 2) / 2

*/
