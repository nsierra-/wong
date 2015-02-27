/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 16:39:37 by nsierra-          #+#    #+#             */
/*   Updated: 2015/01/04 17:20:39 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*cursor;
	t_list	*tmp;

	cursor = *alst;
	tmp = NULL;
	while (cursor)
	{
		tmp = cursor;
		cursor = cursor->next;
	}
	if (tmp)
		tmp->next = new;
	else
		*alst = new;
}
