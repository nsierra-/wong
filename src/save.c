/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 02:46:20 by amaurer           #+#    #+#             */
/*   Updated: 2015/03/01 03:49:03 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <wong.h>
#include <libft.h>
#include <errno.h>

static int	save_set_size(t_2048 *game, int fd)
{
	char	*line;
	char	*tmp;

	get_next_line(fd, &line);

	game->width = ft_atoi(line);
	tmp = ft_strchr(line, ' ');

	if (!tmp)
		return (-1);

	game->height = ft_atoi(tmp + 1);
	tmp = ft_strchr(tmp + 1, ' ');

	if (!tmp)
		return (-1);
	game->base = ft_atoi(tmp + 1);

	if (game->width <= 0 || game->height <= 0 || game->base <= 1)
		return (-1);

	free(line);

	return (R_SUCCESS);
}

static void	free_map(t_2048 *game)
{
	int	y;

	y = 0;
	while (y < game->height)
	{
		free(game->map[y]);
		y++;
	}

	free(game->map);
}

int		save(t_2048 *game)
{
	int		fd;
	int		x;
	int		y;

	fd = open(SAVE_FILE, O_WRONLY | O_CREAT | O_TRUNC);

	if (fd == -1)
		return (R_E_FILE);

	ft_putnbr_fd(game->width, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(game->height, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(game->base, fd);
	ft_putchar_fd('\n', fd);

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while(x < game->width)
		{
			ft_putnbr_fd(game->map[y][x], fd);
			ft_putchar_fd(' ', fd);
			x++;
		}
		ft_putchar_fd('\n', fd);
		y++;
	}

	close(fd);

	return (R_SUCCESS);
}

int		restore_save(t_2048 *game)
{
	int		fd;
	int		x;
	int		y;
	char	*line;
	char	*tmp;

	fd = open(SAVE_FILE, O_RDONLY);

	if (fd == -1)
		return (R_E_FILE);

	free_map(game);

	if (save_set_size(game, fd) == -1)
		return (-1);

	build_map(game);

	y = 0;
	while (get_next_line(fd, &line) > 0 && y < game->height)
	{
		x = 0;
		tmp = line;
		while (tmp && x < game->width)
		{
			game->map[y][x] = 0;
			tmp = ft_strchr(tmp, ' ');
			x++;
		}
		free(line);
		y++;
	}

	close(fd);

	return (R_SUCCESS);
}