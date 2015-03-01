/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:09:08 by nsierra-          #+#    #+#             */
/*   Updated: 2015/02/28 23:18:28 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "libft.h"
#include "wong.h"

static void	game_update(t_2048 *game, int ch)
{
	if (ch == -1 && !(game->running = 0))
		return ;
	if (ch == KEY_DOWN)
		move_down(game);
	else if (ch == KEY_UP)
		move_up(game);
	else if (ch == KEY_LEFT)
		move_left(game);
	else if (ch == KEY_RIGHT)
		move_right(game);
}

static void	game_draw(t_2048 *game)
{
	t_draw_infos	infos;

	wrefresh(stdscr);
	set_max_case_size(game, &infos);
	set_max_number_size(game, &infos);
	set_case_spaces(game, &infos);
	//is_valid(&infos);
	draw_map(game, &infos);
	draw_stats(game);
}

void		game_loop(t_2048 *game)
{
	while (game->running)
	{
		game_update(game, ncurses_handle_input());
		spawn_randomly(game);
		game_draw(game);
	}
}
