/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:43:53 by nsierra-          #+#    #+#             */
/*   Updated: 2015/03/01 08:07:02 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include "libft.h"
#include "wong.h"

static t_2048		*game_init(int ac, char **av)
{
	t_2048			*game;

	game = malloc(sizeof(t_2048));
	game->width = DEFAULT_WIDTH;
	game->height = DEFAULT_HEIGHT;
	game->win_value = DEFAULT_WIN_VALUE;
	game->seed = time(NULL);
	game->base = DEFAULT_BASE;
	game->score = 0;
	game->move_count = 0;
	game->running = 1;
	game->won = 0;
	if (parse_options(game, ac, av))
		return (NULL);
	if (game->width == 0)
		return (NULL);
	if (build_map(game))
		return (NULL);
	ncurses_handling(init);
	ncurses_handling(set_signal);
	srand(game->seed);
	return (game);
}

static void			game_end(t_2048 *game)
{
	int				score;
	struct passwd	*pw;

	ncurses_handling(end);
	score = get_last_highscore();
	pw = getpwuid(geteuid());
	if (game->score >= score)
		highscores_add(pw->pw_name, game->score, 0);
}

int					build_map(t_2048 *game)
{
	int				x;
	int				y;

	game->map = malloc(sizeof(int*) * game->height);
	if (!game->map)
		return (return_error(R_E_MALLOC));
	y = 0;
	while (y < game->height)
	{
		game->map[y] = malloc(sizeof(int) * game->width);
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

int					main(int ac, char **av)
{
	t_2048			*game;

	game = game_init(ac, av);
	if (!game)
		return (EXIT_FAILURE);
	game_start(game);
	game_loop(game);
	game_end(game);
	if (game->won == -1)
		ft_putendl("\nYou lost.");
	return (EXIT_SUCCESS);
}
