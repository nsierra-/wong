/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:59:59 by nsierra-          #+#    #+#             */
/*   Updated: 2015/02/27 21:05:17 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include "wong.h"

void		ncurses_handling(t_ncurses_action action)
{
	if (action == init)
	{
		initscr();
		cbreak();
		noecho();
		keypad(stdscr, TRUE);
	}
	else if (action == end)
	{
		endwin();
	}
}
