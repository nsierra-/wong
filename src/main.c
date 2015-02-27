/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:43:53 by nsierra-          #+#    #+#             */
/*   Updated: 2015/02/27 23:09:02 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "wong.h"

static int		build_map(t_2048 *game)
{
	t_uint	x;
	t_uint	y;

	game->map = malloc(sizeof(t_uint*) * game->height);

	if (!game->map)
		return (return_error(R_E_MALLOC));

	y = 0;
	while (y < game->height)
	{
		game->map[y] = malloc(sizeof(t_uint) * game->width);

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
	game->seed = time(NULL);
	game->base = DEFAULT_BASE;

	if (build_map(game))
		return (NULL);

	// ncurses_handling(init);

	(void) ac;
	(void) av;

	srand(game->seed);

	return (game);
}

// static void		game_end(void)
// {
// 	ncurses_handling(end);
// }

int				main(int ac, char **av)
{
	t_2048	*game;

	game = game_init(ac, av);

	if (!game)
	{
		ft_putendl("ERROR.");
		return (EXIT_FAILURE);
	}

	game_start(game);
	print_map(game);

	// game_end();

	return (EXIT_SUCCESS);
}
