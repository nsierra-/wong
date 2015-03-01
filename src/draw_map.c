/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:31:03 by nsierra-          #+#    #+#             */
/*   Updated: 2015/03/01 00:37:21 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include "libft.h"
#include "wong.h"

static void	draw_sep_line(int x, int y, t_draw_infos *infos)
{
	int		i;

	i = 0;
	while (i < infos->max_case_width)
	{
		if (i == 0 || i == infos->max_case_width - 1)
			mvwaddch(stdscr, y, x, '|');
		else
			mvwaddch(stdscr, y, x, '-');
		++x;
		++i;
	}
}

static void	draw_white_line(int x, int y, t_draw_infos *infos)
{
	int		i;

	i = 0;
	while (i < infos->max_case_width)
	{
		if (i == 0 || i == infos->max_case_width - 1)
			mvwaddch(stdscr, y, x, '|');
		else
			mvwaddch(stdscr, y, x, ' ');
		++x;
		++i;
	}
}

static void	draw_number_line(int x, int y, int value, t_draw_infos *infos)
{
	int		i;
	int		j;
	char	*tmp;

	mvwaddch(stdscr, y, x++, '|');
	i = 0;
	while (i++ < infos->case_hspace)
		waddch(stdscr, ' ');
	tmp = ft_itoa(value);
	waddstr(stdscr, tmp);
	free(tmp);
	i = 0;
	j = infos->max_number_size - get_number_size(value);
	while (i++ < (infos->case_hspace + j))
		waddch(stdscr, ' ');
	waddch(stdscr, '|');
}

static void	draw_case(int x, int y, int value, t_draw_infos *infos)
{
	int		current_y;
	int		current_x;
	int		i;

	current_y = y * infos->max_case_height;
	current_x = x * infos->max_case_width;
	draw_sep_line(current_x, current_y++, infos);
	i = 0;
	while (i++ < infos->case_vspace)
		draw_white_line(current_x, current_y++, infos);
	draw_number_line(current_x, current_y++, value, infos);
	i = 0;
	while (i++ < infos->case_vspace)
		draw_white_line(current_x, current_y++, infos);
	draw_sep_line(current_x, current_y, infos);
}

void		draw_map(t_2048 *game, t_draw_infos *infos)
{
	uint	x;
	uint	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_case(x, y, game->map[y][x], infos);
			x++;
		}
		y++;
	}
}
