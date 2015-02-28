/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:45:19 by amaurer           #+#    #+#             */
/*   Updated: 2015/02/28 23:27:52 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>
#include <libft.h>
#include <stdio.h>

static int		next_number_index(int *line, int index, int length)
{
	while (index < length)
	{
		if (line[index] != 0)
			return (index);
		index++;
	}
	return (-1);
}

static int	slide_line_0(int *line, int index, int length)
{
	int	result;

	result = next_number_index(line, index + 1, length);

	if (result == -1)
		return (-1);

	line[index] = line[result];
	line[result] = 0;

	return (slide_line_left(line, index, length));
}

static int	slide_line_1(int *line, int index, int length)
{
	int	result;

	result = next_number_index(line, index + 1, length);

	if (result == -1)
		return (-1);
	if (line[result] == line[index])
	{
		line[index] += line[result];
		line[result] = 0;
	}
	else
	{
		line[index + 1] = line[result];

		if (index + 1 != result)
			line[result] = 0;
	}

	return (slide_line_left(line, index + 1, length));
}

int		slide_line_left(int *line, int index, int length)
{
	if (index >= length)
		return (-1);

	if (line[index] == 0)
		return slide_line_0(line, index, length);
	else
		return slide_line_1(line, index, length);
}

void		move_left(t_2048 *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		slide_line_left(game->map[i], 0, game->width);
		i++;
	}
}