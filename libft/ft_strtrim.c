/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 23:15:08 by nsierra-          #+#    #+#             */
/*   Updated: 2015/01/04 17:27:01 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static int	find_first_non_blank_char(char const *s, int i)
{
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		++i;
	if (s[i] == '\0')
		return (-1);
	else
		return (i);
}

static int	find_last_non_blank_char(char const *s)
{
	size_t	str_size;
	size_t	i;

	str_size = ft_strlen(s);
	i = str_size - 1;
	while (i > 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		--i;
	if (i + 1 == str_size)
		return (-1);
	return (i + 1);
}

static char	*cut_string(char const *s, int pos_beg)
{
	int		pos_end;

	pos_end = find_last_non_blank_char(s);
	if (pos_end == -1)
		return (ft_strdup(s + pos_beg));
	return (ft_strsub(s, pos_beg, pos_end - pos_beg));
}

char		*ft_strtrim(char const *s)
{
	int		pos_beg;

	if (!s)
		return (NULL);
	else if ((pos_beg = find_first_non_blank_char(s, 0)) == -1)
		return (ft_strnew(1));
	else
		return (cut_string(s, pos_beg));
}
