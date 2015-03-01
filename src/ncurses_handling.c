/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:59:59 by nsierra-          #+#    #+#             */
/*   Updated: 2015/02/28 23:20:55 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <signal.h>
#include "wong.h"

void		ncurses_resize(int sigwinch)
{
	(void)sigwinch;
	endwin();
	refresh();
	clear();
	ncurses_handling(init);
	waddstr(stdscr, "Press any key...");
}

void		ncurses_handling(t_ncurses_action action)
{
	if (action == init)
	{
		initscr();
		cbreak();
		noecho();
		curs_set(0);
		keypad(stdscr, TRUE);
	}
	else if (action == set_signal)
		signal(SIGWINCH, ncurses_resize);
	else if (action == end)
		endwin();
	else if (action == refresh_screen)
		refresh();
}

int			ncurses_handle_input(void)
{
	int		ch;

	ch = getch();
	if (ch == 27)
	{
		nodelay(stdscr, TRUE);
		if (getch() == ERR)
		{
			nodelay(stdscr, FALSE);
			return (-1);
		}
		nodelay(stdscr, FALSE);
	}
	else if (ch == ERR)
		ch = 0;
	return (ch);
}
