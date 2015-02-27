/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:45:19 by amaurer           #+#    #+#             */
/*   Updated: 2015/02/28 00:52:15 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>
#include <libft.h>
#include <stdio.h>

int		next_number_index(t_uint *line, int length)
{
	while (length >= 0)
	{
		if (line[length] != 0)
			return (length);
		length--;
	}

	return (-1);
}

t_uint	slide_line(t_uint *line, int index)
{
	int		result;

	printf("Index %u\n", index);

	if (index < 0)
	{
		printf("Stop\n");
		return (-1);
	}

	if (line[index] == 0)
	{
		printf("Zero\n");
		result = next_number_index(line, index - 1);

		if (result == -1)
			return (-1);

		line[index] = line[result];
		line[result] = 0;
		return slide_line(line, index);
	}
	else
	{
		printf("Non zero\n");
		result = next_number_index(line, index - 1);

		if (result == -1)
			return (-1);

		if (line[result] == line[index])
		{
			printf("    Equal with %u\n", result);
			line[index] += line[result];
			line[result] = 0;
		}
		else
		{
			printf("    Not equal with %u\n", result);
			line[index - 1] = line[result];

			if (index - 1 != result)
				line[result] = 0;
		}

		return slide_line(line, index - 1);
	}

	return (-1);
}

void	move_right(t_2048 *game)
{
	// t_uint	start;
	// t_uint	end;
	// t_uint	x;
	// t_uint	y;

	// start = 0;
	// end = game->width;
	// x = start;

	// y = 0;
	// while (y < game->height)
	// {
	// 	slide_line(game->map[y], game->width);
	// 	y++;
	// }

	slide_line(game->map[0], game->width - 1);
}