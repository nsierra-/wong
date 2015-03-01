/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highscores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 23:40:37 by amaurer           #+#    #+#             */
/*   Updated: 2015/03/01 04:24:28 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include <wong.h>

static char	**highscores_load(void)
{
	char	**scores;
	int		fd;
	char	*line;
	int		i;

	scores = malloc(sizeof(char*) * HIGHSCORES_COUNT + 1);
	if (!scores)
		return (NULL);
	i = 0;
	while (i <= HIGHSCORES_COUNT)
	{
		scores[i] = NULL;
		i++;
	}
	fd = open(HIGHSCORES_FILE, O_RDONLY);
	if (fd == -1)
		return (scores);
	i = 0;
	while (i < HIGHSCORES_COUNT && get_next_line(fd, &line) > 00)
	{
		scores[i] = line;
		++i;
	}
	close(fd);
	return (scores);
}

static char	*build_highscore_line(char *name, int score)
{
	char	*out;
	char	*tmp;

	tmp = ft_itoa(score);
	out = malloc(sizeof(char*) * (ft_strlen(name) + 2 + ft_nbrlen(score)));
	out = ft_strcat(out, tmp);
	out = ft_strcat(out, " ");
	out = ft_strcat(out, name);
	free(tmp);
	return (out);
}

int			highscores_add(char *name, int score, int i)
{
	char	**scores;
	int		fd;
	char	*tmp;

	scores = highscores_load();
	if (!(fd = open(HIGHSCORES_FILE, O_WRONLY | O_CREAT)))
		return (R_E_FILE);
	while (i < HIGHSCORES_COUNT - 1 || (i = 0))
	{
		if (score > 0 && (!scores[i] || score > ft_atoi(scores[i])))
		{
			tmp = build_highscore_line(name, score);
			ft_putendl_fd(tmp, fd);
			free(tmp);
			score = -1;
		}
		if (scores[i])
			ft_putendl_fd(scores[i], fd);
		++i;
	}
	close(fd);
	while (scores[i])
		free(scores[i++]);
	free(scores);
	return (R_SUCCESS);
}

int			get_last_highscore(void)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		score;
	int		i;

	if ((fd = open(HIGHSCORES_FILE, O_RDONLY)) == -1)
		return (0);
	tmp = NULL;
	i = 0;
	while (1)
	{
		if (get_next_line(fd, &line) <= 0)
			break ;
		if (tmp)
			free(tmp);
		tmp = line;
		i++;
	}
	close(fd);
	score = ft_atoi(tmp);
	free(tmp);
	if (i < HIGHSCORES_COUNT)
		return (0);
	return (score);
}
