/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:09:12 by nsierra-          #+#    #+#             */
/*   Updated: 2013/11/26 10:08:42 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t		ft_strlen(const char *str)
{
	size_t		length;

	length = 0;
	if (str)
	{
		while (str[length] != '\0')
		{
			length++;
		}
	}
	return (length);
}
