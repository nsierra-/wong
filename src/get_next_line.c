/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 10:02:23 by nsierra-          #+#    #+#             */
/*   Updated: 2015/03/01 01:03:02 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <wong.h>

static void				push_buf(char **remaining, char *buf)
{
	char				*tmp;

	tmp = *remaining;
	*remaining = ft_strjoin(*remaining, buf);
	free(tmp);
}

static void				load_line(char **line, char **remaining, char *found)
{
	char				*tmp;

	*line = ft_strdup(*remaining);
	if (found)
	{
		tmp = *remaining;
		*remaining = ft_strdup(found + 1);
		free(tmp);
	}
	else
		*remaining = NULL;
}

static int				find_newline(char **line, char **remaining)
{
	char				*found;

	if (*remaining && (found = ft_strchr(*remaining, '\n')))
	{
		*found = '\0';
		load_line(line, remaining, found);
		return (1);
	}
	return (0);
}

int						get_next_line(int const fd, char **line)
{
	static char			*remaining = NULL;
	char				buf[BUFF_SIZE + 1];
	int					read_status;

	if (fd < 1 || !line)
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (find_newline(line, &remaining))
		return (1);
	else if ((read_status = read(fd, buf, BUFF_SIZE)) <= 0)
	{
		if (ft_strlen(remaining) > 0)
			load_line(line, &remaining, NULL);
		return (read_status);
	}
	else if (!remaining)
		remaining = ft_strnew(0);
	push_buf(&remaining, buf);
	return (get_next_line(fd, line));
}
