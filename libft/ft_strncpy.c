/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:50:51 by nsierra-          #+#    #+#             */
/*   Updated: 2015/01/04 13:45:28 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char			*ft_strncpy(char *dst, const char *src, size_t n)
{
	int			n2;
	char		*save;

	save = dst;
	n2 = (int)n;
	while (n2--)
		*dst++ = *src++;
	if (n2 > 0)
		*dst++ = '\0';
	return (save);
}
