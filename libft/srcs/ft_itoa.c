/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <acarmela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:14:44 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/24 13:25:48 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_count(int n)
{
	if ((n / 10) != 0)
		return (1 + ft_count(n / 10));
	else
		return (1);
}

static int	ft_sign(int n)
{
	if (n < 0)
		return (-1);
	else
		return (0);
}

static char	ft_integer(int n)
{
	if (n < 0)
	{
		if (n > (-10))
			return (-n);
		else
			return ((n % 10) * -1);
	}
	else
	{
		if (n < 10)
			return (n);
		else
			return (n % 10);
	}
}

char	*ft_itoa(int n)
{
	int		count;
	int		sign;
	int		len;
	char	*a;

	count = ft_count(n);
	sign = ft_sign(n);
	len = count - sign;
	a = (char *)malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	a[len] = '\0';
	while (len--)
	{
		a[len] = ft_integer(n) + 48;
		n = n / 10;
	}
	if (sign < 0)
		a[0] = '-';
	return (a);
}
