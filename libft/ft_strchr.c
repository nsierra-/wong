/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:06:28 by nsierra-          #+#    #+#             */
/*   Updated: 2015/01/04 17:24:06 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cursor;
	char	to_find;
	int		found;
	int		i;

	cursor = (char *)s;
	to_find = (char)c;
	found = 0;
	i = 0;
	while ((!found) && cursor[i] != '\0')
	{
		if (cursor[i] == to_find)
		{
			found = 1;
			break ;
		}
		i++;
		if (to_find == '\0' && cursor[i] == '\0')
			return (&cursor[i]);
	}
	if (found)
		return (&cursor[i]);
	else
		return (NULL);
}
