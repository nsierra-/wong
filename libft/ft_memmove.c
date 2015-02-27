/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:25:37 by nsierra-          #+#    #+#             */
/*   Updated: 2013/11/26 10:05:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*buf;

	buf = (unsigned char *)malloc(sizeof(buf) * n);
	ft_memcpy(buf, s2, n);
	ft_memcpy(s1, buf, n);
	free(buf);
	return (s1);
}
