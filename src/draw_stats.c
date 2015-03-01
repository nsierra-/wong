/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 01:54:05 by nsierra-          #+#    #+#             */
/*   Updated: 2015/03/01 01:55:41 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include "libft.h"
#include "wong.h"

void		draw_stats(t_2048 *game)
{
	char	*tmp;

	mvwaddstr(stdscr, LINES - 1, 0, "Score: ");
	tmp = ft_itoa(game->score);
	waddstr(stdscr, tmp);
	free(tmp);
}