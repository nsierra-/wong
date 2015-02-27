/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:03:53 by nsierra-          #+#    #+#             */
/*   Updated: 2015/01/04 17:26:42 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static void			norme_init(unsigned long *i, unsigned long *j)
{
	*i = 0;
	*j = 0;
}

char				*ft_strstr(const char *s1, const char *s2)
{
	unsigned long	i;
	unsigned long	j;
	char			*s1_cursor;
	char			*s2_cursor;

	s1_cursor = (char *)s1;
	s2_cursor = (char *)s2;
	if (!*s2)
		return ((char *)s1);
	norme_init(&i, &j);
	while (s1_cursor[i] != '\0')
	{
		if (s1_cursor[i] == s2_cursor[j])
		{
			while (s2_cursor[j++] == s1_cursor[i++])
			{
				if (s2_cursor[j] == '\0')
					return (&s1_cursor[i - j]);
			}
			i -= j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
