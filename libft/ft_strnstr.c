/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:37:45 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/01 23:30:36 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int	ft_checkn_pattern(const char *s1, const char *s2, size_t n, int i)
{
	while (*s2 == s1[i] && *s2 != '\0' && i < (int)n)
	{
		s2++;
		i++;
	}
	if (*s2 == '\0')
		return (1);
	else
		return (0);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	if (*s2 != '\0')
	{
		while (s1[i] != '\0' && i < (int)n)
		{
			if (s1[i] == *s2)
			{
				if (ft_checkn_pattern(s1, s2, n, i))
					return ((char *)&s1[i]);
			}
			i++;
		}
		return (NULL);
	}
	else
		return ((char *)s1);
}
