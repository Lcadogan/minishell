/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:53:55 by acarmela          #+#    #+#             */
/*   Updated: 2021/04/18 21:56:59 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;
	size_t			i;

	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s_1[i] != s_2[i])
			return ((int)(s_1[i] - s_2[i]));
		i++;
	}
	return (0);
}
