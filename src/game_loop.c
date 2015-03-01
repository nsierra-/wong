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

static int	game_update(t_2048 *game, int ch)
{
	int		ret;

	ret = 0;
	if (ch == -1 && !(game->running = 0))
		return (ret);
	if (ch == KEY_DOWN && (ret = 1))
		move_down(game);
	else if (ch == KEY_UP && (ret = 1))
		move_up(game);
	else if (ch == KEY_LEFT && (ret = 1))
		move_left(game);
	else if (ch == KEY_RIGHT && (ret = 1))
		move_right(game);
	return (ret);
}

static void	game_draw(t_2048 *game)
{
	t_draw_infos	infos;

	wrefresh(stdscr);
	set_max_case_size(game, &infos);
	set_max_number_size(game, &infos);
	set_case_spaces(game, &infos);
	draw_map(game, &infos);
	draw_stats(game);
}

static int	has_won(t_2048 *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] >= game->win_value)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void		game_loop(t_2048 *game)
{
	int		valid_move;

	valid_move = 0;
	while (game->running)
	{
		game_draw(game);
		valid_move = game_update(game, ncurses_handle_input());
		game_draw(game);
		if (valid_move)
		{
			if (spawn_randomly(game) == R_BOARD_FULL)
			{
				game->won = -1;
				return ;
			}
		}
		if (has_won(game))
			game->won = 1;
	}
}
