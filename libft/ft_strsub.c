/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 23:07:51 by nsierra-          #+#    #+#             */
/*   Updated: 2013/11/26 14:40:00 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str_sub;
	size_t	i;

	i = 0;
	str_sub = malloc(sizeof(char *) * len + 1);
	if (str_sub)
	{
		while (len)
		{
			str_sub[i++] = s[start++];
			len--;
		}
		str_sub[i] = '\0';
		return (str_sub);
	}
	else
		return (NULL);
}
