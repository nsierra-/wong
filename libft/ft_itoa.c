/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 23:21:21 by nsierra-          #+#    #+#             */
/*   Updated: 2015/01/04 17:22:50 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void reverse(char *str, int length)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = length - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

char		*ft_itoa(int n)
{
	char	*result;
	int		sign;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = n < 0 ? 1 : 0;
	i = 0;
	result = malloc(sizeof(char *) * 12);
	if (n == 0)
		result[i++] = '0';
	else if (n < 0)
	{
		result[i++] = '-';
		n = -n;
	}
	while (n > 0)
	{
		result[i++] = '0' + n % 10;
		n /= 10;
	}
	reverse(result + sign, i - sign);
	result[i] = '\0';
	return (result);
}
