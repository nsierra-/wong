/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:46:07 by nsierra-          #+#    #+#             */
/*   Updated: 2013/11/26 14:37:05 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*m_new;

	m_new = (unsigned char *)malloc(sizeof(m_new) * size);
	if (m_new)
	{
		ft_bzero(m_new, size);
		return (m_new);
	}
	return (NULL);
}
