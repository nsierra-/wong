/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:34:40 by nsierra-          #+#    #+#             */
/*   Updated: 2013/11/26 10:05:21 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*keep;
	const char	*src_as_cc;

	keep = dest;
	src_as_cc = src;
	while (n-- != 0)
		*(char *)dest++ = *src_as_cc++;
	return (keep);
}
