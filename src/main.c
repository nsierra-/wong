/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:43:53 by nsierra-          #+#    #+#             */
/*   Updated: 2015/02/27 23:10:35 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "wong.h"

static int		build_map(t_2048 *game)
{
	uint	x;
	uint	y;

	game->map = malloc(sizeof(uint*) * game->height);

	if (!game->map)
		return (return_error(R_E_MALLOC));

	y = 0;
	while (y < game->height)
	{
		game->map[y] = malloc(sizeof(uint) * game->width);

		if (!game->map[y])
			return (return_error(R_E_MALLOC));

		x = 0;
		while (x < game->width)
		{
			game->map[y][x] = 0;
			x++;
		}
		y++;
	}

	return (R_SUCCESS);
}

static t_2048	*game_init(int ac, char **av)
{
	t_2048	*game;

	game = malloc(sizeof(t_2048));
	game->width = DEFAULT_WIDTH;
	game->height = DEFAULT_HEIGHT;
	game->win_value = DEFAULT_WIN_VALUE;
	game->score = 0;
	game->move_count = 0;
	game->running = 1;

	if (parse_options(game, ac, av))
		return (NULL);
	print_game(game);
	if (build_map(game))
		return (NULL);

	ncurses_handling(init);
	ncurses_handling(set_signal);

	(void) ac;
	(void) av;

	return (game);
}

static void		game_end(void)
{
	ncurses_handling(end);
}

int				main(int ac, char **av)
{
	t_2048	*game;

	game = game_init(ac, av);

	if (!game)
	{
		ft_putendl("ERROR.");
		return (EXIT_FAILURE);
	}

	print_map(game);
	game_loop(game);
	game_end();
	return (0);
}
