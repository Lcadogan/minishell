/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <acarmela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:18:55 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/24 13:26:53 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_tab(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	return (i);
}

static int	ft_symb(const char *str, int i)
{
	int		symb;

	if (str[i] == 45)
		symb = -1;
	else
		symb = 1;
	return (symb);
}

static int	ft_res(const char *str, int i, int symb)
{
	long	res;

	res = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (res > (res * 10 + (str[i] - 48)))
		{
			if (symb == 1)
				return (-1);
			if (symb == -1)
				return (0);
		}
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		symb;

	if (ft_strlen(str) == 0)
		return (0);
	i = ft_tab(str);
	symb = ft_symb(str, i);
	if (str[i] == 43 || str[i] == 45)
		i++;
	res = ft_res(str, i, symb);
	return ((int)res * symb);
}
