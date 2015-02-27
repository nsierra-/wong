/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:36:02 by nsierra-          #+#    #+#             */
/*   Updated: 2013/11/26 10:08:30 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	s1_char;
	unsigned char	s2_char;

	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	s1_char = (*(unsigned char *)s1);
	s2_char = (*(unsigned char *)s2);
	return (s1_char - s2_char);
}
