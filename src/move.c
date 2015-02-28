/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:45:19 by amaurer           #+#    #+#             */
/*   Updated: 2015/02/28 01:13:24 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>
#include <libft.h>
#include <stdio.h>

static int		next_number_index(t_uint *line, int length)
{
	while (length >= 0)
	{
		if (line[length] != 0)
			return (length);
		length--;
	}

	return (-1);
}

static t_uint	slide_line_right_0(t_uint *line, int index)
{
	int	result;

	result = next_number_index(line, index - 1);

	if (result == -1)
		return (-1);

	line[index] = line[result];
	line[result] = 0;

	return (slide_line_right(line, index));
}

static t_uint	slide_line_right_1(t_uint *line, int index)
{
	int	result;

	result = next_number_index(line, index - 1);

	if (result == -1)
		return (-1);
	if (line[result] == line[index])
	{
		line[index] += line[result];
		line[result] = 0;
	}
	else
	{
		line[index - 1] = line[result];

		if (index - 1 != result)
			line[result] = 0;
	}

	return (slide_line_right(line, index - 1));
}

t_uint		slide_line_right(t_uint *line, int index)
{
	if (index < 0)
		return (-1);

	if (line[index] == 0)
		return slide_line_right_0(line, index);
	else
		return slide_line_right_1(line, index);

}

void		move_right(t_2048 *game)
{
	slide_line_right(game->map[0], game->width - 1);
}