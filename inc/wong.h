/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:43:20 by nsierra-          #+#    #+#             */
/*   Updated: 2015/02/28 00:53:01 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_H
# define WONG_H

# define				DEFAULT_BASE		3
# define				DEFAULT_WIDTH		4
# define				DEFAULT_HEIGHT		4
# define				DEFAULT_WIN_VALUE	2048
# define				R_SUCCESS			0
# define				R_E_MALLOC			1
# define				R_E_BAD_COORD		2
# define				R_BOARD_FULL		3

typedef unsigned int	t_uint;

typedef struct			s_2048
{
	t_uint				width;
	t_uint				height;
	t_uint				score;
	t_uint				**map;
	t_uint				win_value;
	t_uint				move_count;
	t_uint				seed;
	t_uint				base;
}						t_2048;

typedef enum			e_ncurses_action
{
	init,
	end
}						t_ncurses_action;

void		ncurses_handling(t_ncurses_action action);
int			return_error(int error_code);
void		print_map(t_2048 *game);

int			game_start(t_2048 *game);
int			spawn_value(t_2048 *game, t_uint x, t_uint y, t_uint value);

void		move_left(t_2048 *game);
void		move_right(t_2048 *game);
void		move_up(t_2048 *game);
void		move_down(t_2048 *game);

#endif

/*

2 2 0 2
0 2 0 2

Index 3
Non zero
    Equal
Index 2
Zero
Index 2
Non zero

*/