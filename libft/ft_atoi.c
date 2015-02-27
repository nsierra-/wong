/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:30:43 by nsierra-          #+#    #+#             */
/*   Updated: 2015/01/04 13:54:58 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int					ft_atoi(const char *str)
{
	int		nb;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\n' || str[i] == '\v')
		++i;
	if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		++i;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		sign = -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		++i;
	}
	return (sign * nb);
}
