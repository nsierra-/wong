/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:43:20 by nsierra-          #+#    #+#             */
/*   Updated: 2015/02/27 21:14:05 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_H
# define WONG_H

# define				DEFAULT_WIDTH		4
# define				DEFAULT_HEIGHT		4
# define				DEFAULT_WIN_VALUE	2048

typedef unsigned int	uint;

typedef struct			s_2048
{
	uint				width;
	uint				height;
	uint				score;
	uint				**map;
	uint				win_value;
	uint				move_count;
}						t_2048;

#endif
