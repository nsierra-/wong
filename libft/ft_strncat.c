/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:33:43 by nsierra-          #+#    #+#             */
/*   Updated: 2015/01/04 17:24:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char			*keep;
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	keep = s1;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0' && n > 0)
	{
		s1[i++] = s2[j++];
		n--;
	}
	s1[i] = '\0';
	return (keep);
}
