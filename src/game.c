/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:00:44 by amaurer           #+#    #+#             */
/*   Updated: 2015/02/28 00:52:59 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>
#include <stdlib.h>
#include <libft.h>

int		spawn_value(t_2048 *game, t_uint x, t_uint y, t_uint value)
{
	if (x >= game->width || y >= game->height)
		return (return_error(R_E_BAD_COORD));

	game->map[y][x] = value;

	return (R_SUCCESS);
}

// static t_uint	get_free_block_count(t_2048 *game)
// {
// 	t_uint	y;
// 	t_uint	x;
// 	t_uint	i;

// 	i = 0;
// 	y = 0;
// 	while (y < game->height)
// 	{
// 		x = 0;
// 		while (x < game->width)
// 		{
// 			if (game->map[y][x] == 0)
// 				i++;
// 			x++;
// 		}
// 		y++;
// 	}

// 	return (i);
// }

// static t_uint	**get_free_blocks(t_2048 *game, t_uint *i)
// {
// 	t_uint	**blocks;
// 	t_uint	y;
// 	t_uint	x;

// 	blocks = malloc(sizeof(t_uint*) * get_free_block_count(game) + 1);

// 	*i = 0;
// 	y = 0;
// 	while (y < game->height)
// 	{
// 		x = 0;
// 		while (x < game->width)
// 		{
// 			if (game->map[y][x] == 0)
// 			{
// 				blocks[*i] = malloc(sizeof(t_uint) * 2);
// 				blocks[*i][0] = x;
// 				blocks[*i][1] = y;
// 				(*i)++;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}

// 	blocks[*i] = NULL;

// 	return (blocks);
// }

// static int	spawn_randomly(t_2048 *game)
// {
// 	t_uint	value;
// 	t_uint	i;
// 	t_uint	**blocks;
// 	t_uint	random;
// 	t_uint	j;

// 	if (rand() % 3 != 0)
// 		value = game->base;
// 	else
// 		value = game->base * game->base;

// 	blocks = get_free_blocks(game, &i);

// 	if (i == 0)
// 		return (return_error(R_BOARD_FULL));

// 	random = rand() % (i - 1);

// 	spawn_value(game, blocks[random][0], blocks[random][1], value);

// 	j = 0;
// 	while (j < i)
// 		free(blocks[j++]);
// 	free(blocks);

// 	return (R_SUCCESS);
// }

int		game_start(t_2048 *game)
{
	// spawn_randomly(game);
	// spawn_randomly(game);
	spawn_value(game, 0, 0, 3);
	spawn_value(game, 1, 0, 3);
	spawn_value(game, 2, 0, 3);
	spawn_value(game, 3, 0, 3);

	print_map(game);

	move_right(game);

	return (R_SUCCESS);
}