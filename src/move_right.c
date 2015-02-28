/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:45:19 by amaurer           #+#    #+#             */
/*   Updated: 2015/02/28 23:27:51 by amaurer          ###   ########.fr       */
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

static int	slide_line_0(int *line, int index)
{
	int	result;

	result = next_number_index(line, index - 1);

	if (result == -1)
		return (-1);

	line[index] = line[result];
	line[result] = 0;

	return (slide_line_right(line, index));
}

static int	slide_line_1(int *line, int index)
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

int		slide_line_right(int *line, int index)
{
	if (index < 0)
		return (-1);

	if (line[index] == 0)
		return slide_line_0(line, index);
	else
		return slide_line_1(line, index);

}

void		move_right(t_2048 *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		slide_line_right(game->map[i], game->width - 1);
		i++;
	}
}