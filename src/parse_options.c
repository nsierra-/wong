/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:57:22 by nsierra-          #+#    #+#             */
/*   Updated: 2015/02/27 22:54:46 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"
#include "libft.h"
#include <time.h>

static void	print_usage(void)
{
	ft_putendl("Usage : ./game_2048 [-whsbm]");
}

static void	print_error(int type, char *option, int def)
{
	if (type == 0)
	{
		ft_putstr("No value given for ");
		ft_putstr(option);
		ft_putstr(". Using default value (");
		ft_putnbr(def);
		ft_putendl(")");
	}
	else if (type == 1)
	{
		ft_putstr("Invalid value for ");
		ft_putstr(option);
		ft_putstr(". Using default value (");
		ft_putnbr(def);
		ft_putendl(")");
	}
}

static void	set_number_value(int *to_set, char *option, char *val, int def)
{
	int		i;
	int		error;

	error = 0;
	if (!val && (error = 1))
		print_error(0, option, def);
	i = 0;
	while (!error && val[i] != '\0')
	{
		if (!ft_isdigit(val[i]) && (error = 1))
			print_error(1, option, def);
		++i;
	}
	if (error)
		*to_set = def;
	else
	{
		i = ft_atoi(val);
		if (i <= 0 && (*to_set = def))
			print_error(1, option, def);
		else
			*to_set = i;
	}
}

int			parse_options(t_2048 *game, int ac, char **av)
{
	int		i = 1;

	(void)game;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-w"))
			set_number_value((int *)&game->width, "-w", av[i + 1], DEFAULT_WIDTH);
		else if (!ft_strcmp(av[i], "-h"))
			set_number_value((int *)&game->height, "-h", av[i + 1], DEFAULT_HEIGHT);
		else if (!ft_strcmp(av[i], "-s"))
			set_number_value((int *)&game->seed, "-s", av[i + 1], time(NULL));
		else if (!ft_strcmp(av[i], "-b"))
			set_number_value((int *)&game->base, "-b", av[i + 1], DEFAULT_BASE);
		else if (!ft_strcmp(av[i], "-m"))
			set_number_value((int *)&game->win_value, "-m", av[i + 1], DEFAULT_WIN_VALUE);
		else
		{
			print_usage();
			return (R_E_OPTION);
		}
		i += 2;
	}
	return (0);
}
