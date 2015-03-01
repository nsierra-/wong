/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:00:44 by amaurer           #+#    #+#             */
/*   Updated: 2015/03/01 04:23:28 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>
#include <stdlib.h>
#include <libft.h>

int			spawn_value(t_2048 *game, int x, int y, int value)
{
	if (x >= game->width || y >= game->height)
		return (return_error(R_E_BAD_COORD));
	game->map[y][x] = value;
	return (R_SUCCESS);
}

static int	get_free_block_count(t_2048 *game)
{
	int		y;
	int		x;
	int		i;

	i = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 0)
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

static int	**get_free_blocks(t_2048 *game, int *i)
{
	int		**blocks;
	int		y;
	int		x;

	blocks = malloc(sizeof(int*) * get_free_block_count(game) + 1);
	*i = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 0)
			{
				blocks[*i] = malloc(sizeof(int) * 2);
				blocks[*i][0] = x;
				blocks[*i][1] = y;
				(*i)++;
			}
			x++;
		}
		y++;
	}
	blocks[*i] = NULL;
	return (blocks);
}

int			spawn_randomly(t_2048 *game)
{
	int		value;
	int		i;
	int		**blocks;
	int		random;
	int		j;

	if (rand() % 6 != 0)
		value = game->base;
	else
		value = game->base * game->base;
	blocks = get_free_blocks(game, &i);
	if (i == 0 && !(j = 0))
	{
		while (j < i)
			free(blocks[j++]);
		free(blocks);
		return (return_error(R_BOARD_FULL));
	}
	random = rand() % (i);
	spawn_value(game, blocks[random][0], blocks[random][1], value);
	j = 0;
	while (j < i)
		free(blocks[j++]);
	free(blocks);
	return (R_SUCCESS);
}

int			game_start(t_2048 *game)
{
	spawn_randomly(game);
	spawn_randomly(game);
	return (R_SUCCESS);
}
