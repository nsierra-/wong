/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:35:16 by nsierra-          #+#    #+#             */
/*   Updated: 2013/11/26 10:08:46 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dest;
	const char	*str;
	size_t		n;
	size_t		dest_length;

	dest = dst;
	str = src;
	n = size;
	while (n-- != 0 && *dest != '\0')
		dest++;
	dest_length = dest - dst;
	n = size - dest_length;
	if (n == 0)
		return (dest_length + ft_strlen((char *)str));
	while (*str != '\0')
	{
		if (n != 1)
		{
			*dest++ = *str;
			n--;
		}
		str++;
	}
	*dest = '\0';
	return (dest_length + (str - src));
}
