/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_new_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 05:30:40 by nsierra-          #+#    #+#             */
/*   Updated: 2013/11/29 05:38:48 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_set_new_str(const char *s)
{
	char	*set_str;
	size_t	str_size;

	str_size = ft_strlen(s);
	set_str = ft_strnew(str_size);
	ft_strcpy(set_str, s);
	return (set_str);
}
