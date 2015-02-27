/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 15:35:16 by nsierra-          #+#    #+#             */
/*   Updated: 2015/01/04 15:48:45 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cursor;
	t_list	*tmp;

	if (!alst)
		return ;
	cursor = *alst;
	while (cursor)
	{
		tmp = cursor->next;
		del(cursor, cursor->content_size);
		free(cursor);
		cursor = tmp;
	}
	*alst = NULL;
}
