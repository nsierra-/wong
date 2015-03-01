/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highscores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 23:40:37 by amaurer           #+#    #+#             */
/*   Updated: 2015/03/01 02:15:21 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include <wong.h>

static char	**highscores_load(void)
{
	char	**scores = { NULL };
	int		fd;
	char	*line;
	int		i;

	scores = malloc(sizeof(char*) * HIGHSCORES_COUNT);

	if (!scores)
		return (NULL);

	i = 0;
	while (i < HIGHSCORES_COUNT)
	{
		scores[i] = NULL;
		i++;
	}

	fd = open(HIGHSCORES_FILE, O_RDONLY);

	if (fd == -1)
		return (scores);

	i = 0;
	while (get_next_line(fd, &line) > 0 && i < HIGHSCORES_COUNT)
	{
		scores[i] = line;
		i++;
	}

	close(fd);

	return (scores);
}

static char	*build_highscore_line(char *name, int score)
{
	char	*out;

	out = malloc(sizeof(char*) * (ft_strlen(name) + 2 + ft_nbrlen(score)));
	out = ft_strcat(out, ft_itoa(score));
	out = ft_strcat(out, " ");
	out = ft_strcat(out, name);

	return (out);
}

int		highscores_add(char *name, int score)
{
	char	**scores;
	int		i;
	int		fd;
	char	*tmp;

	scores = highscores_load();

	if (!scores)
		return (return_error(R_E_MALLOC));

	fd = open(HIGHSCORES_FILE, O_WRONLY | O_CREAT);

	if (!fd)
		return (R_E_FILE);

	i = 0;
	while (i < HIGHSCORES_COUNT - 1)
	{
		if (score > 0 && (!scores[i] || score > ft_atoi(scores[i])))
		{
			tmp = build_highscore_line(name, score);
			ft_putendl_fd(tmp, fd);
			free(tmp);
			score = -1;
		}

		if (scores[i])
		{
			ft_putendl_fd(scores[i], fd);
			free(scores[i]);
		}
		i++;
	}

	close(fd);

	return (R_SUCCESS);
}
