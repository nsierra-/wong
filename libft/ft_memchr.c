/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:29:10 by nsierra-          #+#    #+#             */
/*   Updated: 2015/01/04 12:03:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cursor;

	if (!s)
		return (NULL);
	s_cursor = (unsigned char *)s;
	while (n--)
	{
		if (*s_cursor != (unsigned char)c)
			s_cursor++;
		else
			return (s_cursor);
	}
	return (NULL);
}
