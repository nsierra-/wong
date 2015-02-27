/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:36:41 by nsierra-          #+#    #+#             */
/*   Updated: 2015/01/04 17:24:42 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	s1_char;
	unsigned char	s2_char;

	if (n == 0)
		return (n);
	while (*s1 == *s2 && *s1 != '\0' && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	s1_char = (*(unsigned char *)s1);
	s2_char = (*(unsigned char *)s2);
	return (s1_char - s2_char);
}
