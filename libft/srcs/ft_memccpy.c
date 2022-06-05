/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:36:01 by acarmela          #+#    #+#             */
/*   Updated: 2021/04/18 21:58:09 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	z;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	z = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == z)
			return (&d[i + 1]);
		i++;
	}
	return (NULL);
}
