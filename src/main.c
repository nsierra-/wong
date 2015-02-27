/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:43:53 by nsierra-          #+#    #+#             */
/*   Updated: 2015/02/27 21:07:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "wong.h"

static void		init_game(void)
{
	ncurses_handling(init);
}

static void		end_game(void)
{
	ncurses_handling(end);
}

int				main(int ac, char **av)
{
	(void)ac;
	(void)av;
	init_game();
	end_game();
	return (0);
}
