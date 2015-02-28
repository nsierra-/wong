/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:43:20 by nsierra-          #+#    #+#             */
/*   Updated: 2015/02/27 23:57:24 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_H
# define WONG_H

# define				DEFAULT_BASE		2
# define				DEFAULT_WIDTH		4
# define				DEFAULT_HEIGHT		4
# define				DEFAULT_WIN_VALUE	2048
# define				R_SUCCESS			0
# define				R_E_MALLOC			1
# define				R_E_OPTION			2

typedef unsigned int	uint;

typedef struct			s_2048
{
	uint				width;
	uint				height;
	uint				score;
	uint				**map;
	uint				win_value;
	uint				move_count;
	uint				seed;
	uint				base;
	int					running;
}						t_2048;

typedef struct			s_draw_infos
{
	int					valid;
	int					max_case_height;
	int					max_case_width;
	int					max_number_size;
}						t_draw_infos;

typedef enum			e_ncurses_action
{
	init,
	end,
	refresh_screen
}						t_ncurses_action;

void		ncurses_handling(t_ncurses_action action);
int			ncurses_handle_input(void);

void		get_max_case_size(t_2048 *game, t_draw_infos *infos);
void		get_max_number_size(t_2048 *game);
int			is_valid(t_draw_infos *infos);

int			return_error(int error_code);
void		print_map(t_2048 *game);
void		print_game(t_2048 *game);

void		game_loop(t_2048 *game);

int			parse_options(t_2048 *game, int ac, char **av);

void		move_left(t_2048 *game);
void		move_right(t_2048 *game);
void		move_up(t_2048 *game);
void		move_down(t_2048 *game);

#endif
