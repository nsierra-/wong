/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:18:49 by nsierra-          #+#    #+#             */
/*   Updated: 2013/11/26 10:04:00 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*src_as_uc;

	src_as_uc = (unsigned char *)s2;
	while (n-- != 0)
	{
		if (*src_as_uc == (unsigned char)c)
		{
			*(unsigned char *)s1++ = *src_as_uc;
			return (s1);
		}
		else
			*(unsigned char *)s1++ = *src_as_uc++;
	}
	return (NULL);
}
