/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:36:01 by nsierra-          #+#    #+#             */
/*   Updated: 2013/11/26 10:08:38 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(ft_strlen(s1) + 1);
	if (dup == NULL)
		return (NULL);
	else
	{
		while (s1[i] != '\0')
		{
			dup[i] = s1[i];
			i = i + 1;
		}
	}
	dup[i] = '\0';
	return (dup);
}
