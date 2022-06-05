/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:41:55 by acarmela          #+#    #+#             */
/*   Updated: 2021/04/18 21:56:13 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (src > dst)
		while (len--)
			*d++ = *s++;
	else
		while (len--)
			d[len] = s[len];
	return (dst);
}
