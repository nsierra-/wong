/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:59:59 by nsierra-          #+#    #+#             */
/*   Updated: 2015/02/27 23:27:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <signal.h>
#include "wong.h"

void		ncurses_resize(int sigwinch)
{
	(void)sigwinch;
	ncurses_handling(end);
	ncurses_handling(init);
}

void		ncurses_handling(t_ncurses_action action)
{
	if (action == init)
	{
		initscr();
		cbreak();
		noecho();
		keypad(stdscr, TRUE);
		signal(SIGWINCH, ncurses_resize);
	}
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
		if (getch() == ERR)
			return (-1);
	}
	return (ch);
}
