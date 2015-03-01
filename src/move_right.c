/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:45:19 by amaurer           #+#    #+#             */
/*   Updated: 2015/03/01 03:57:21 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>
#include <libft.h>
#include <stdio.h>

static int		next_number_index(int *line, int length)
{
	while (length >= 0)
	{
		if (line[length] != 0)
			return (length);
		length--;
	}

	return (-1);
}

static int	slide_line_0(t_2048 *game, int *line, int index)
{
	int	result;

	result = next_number_index(line, index - 1);

	if (result == -1)
		return (-1);

	line[index] = line[result];
	line[result] = 0;

	return (slide_line_right(game, line, index));
}

static int	slide_line_1(t_2048 *game, int *line, int index)
{
	int	result;

	result = next_number_index(line, index - 1);

	if (result == -1)
		return (-1);
	if (line[result] == line[index])
	{
		game->score += line[result] * 2;
		line[index] += line[result];
		line[result] = 0;
	}
	else
	{
		line[index - 1] = line[result];

		if (index - 1 != result)
			line[result] = 0;
	}

	return (slide_line_right(game, line, index - 1));
}

int		slide_line_right(t_2048 *game, int *line, int index)
{
	if (index < 0)
		return (-1);

	if (line[index] == 0)
		return slide_line_0(game, line, index);
	else
		return slide_line_1(game, line, index);

}

void		move_right(t_2048 *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		slide_line_right(game, game->map[i], game->width - 1);
		i++;
	}
}