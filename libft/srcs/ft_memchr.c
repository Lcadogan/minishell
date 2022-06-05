/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:41:59 by acarmela          #+#    #+#             */
/*   Updated: 2021/04/18 21:57:39 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	unsigned char	tmp_c;
	size_t			i;

	tmp_s = (unsigned char *)s;
	tmp_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*tmp_s++ == tmp_c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
