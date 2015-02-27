/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 23:13:22 by nsierra-          #+#    #+#             */
/*   Updated: 2015/01/04 14:01:42 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	total_size;
	char	*str_new;

	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str_new = malloc(sizeof(char *) * total_size);
	if (str_new && s1 && s2)
	{
		if (*s1 == '\0' && *s2 == '\0' && !(*str_new = '\0'))
			return (str_new);
		ft_strcpy(str_new, s1);
		ft_strlcat(str_new, s2, total_size);
		return (str_new);
	}
	else
		return (NULL);
}
