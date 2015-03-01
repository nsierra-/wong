/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:43:20 by nsierra-          #+#    #+#             */
/*   Updated: 2015/03/01 02:14:33 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_H
# define WONG_H

# define				HIGHSCORES_FILE		"highscores.txt"
# define				HIGHSCORES_COUNT	5
# define				DEFAULT_BASE		2
# define				DEFAULT_WIDTH		4
# define				DEFAULT_HEIGHT		4
# define				DEFAULT_WIN_VALUE	2048
# define				R_SUCCESS			0
# define				R_E_MALLOC			1
# define				R_E_BAD_COORD		2
# define				R_E_FILE			3
# define				R_BOARD_FULL		4
# define				BUFF_SIZE			512

typedef struct			s_2048
{
	int				width;
	int				height;
	int				score;
	int				**map;
	int				win_value;
	int				move_count;
	int				seed;
	int				base;
}						t_2048;

typedef enum			e_ncurses_action
{
	init,
	end
}						t_ncurses_action;

int			get_next_line(int const fd, char **line);

void		ncurses_handling(t_ncurses_action action);
int			return_error(int error_code);
void		print_map(t_2048 *game);

int			game_start(t_2048 *game);
int			spawn_value(t_2048 *game, int x, int y, int value);
int			slide_line_right(int *line, int index);
int			slide_line_left(int *line, int index, int length);
int			slide_line_up(t_2048 * game, int x, int y);
int			slide_line_down(t_2048 * game, int x, int y);

void		move_left(t_2048 *game);
void		move_right(t_2048 *game);
void		move_up(t_2048 *game);
void		move_down(t_2048 *game);

int			highscores_add(char *name, int score);

int			ft_nbrlen(int n);

#endif