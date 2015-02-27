/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 15:26:32 by nsierra-          #+#    #+#             */
/*   Updated: 2015/01/04 16:16:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;

	if (!(new_elem = malloc(sizeof(t_list))))
		return (NULL);
	new_elem->content_size = 0;
	if (content_size && !(new_elem->content = malloc(content_size)))
	{
		free(new_elem);
		return (NULL);
	}
	if (!content || !content_size)
		new_elem->content = NULL;
	else
		ft_memcpy(new_elem->content, content, content_size);
	return (new_elem);
}
