/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <acarmela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:31:49 by acarmela          #+#    #+#             */
/*   Updated: 2021/04/27 09:27:47 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	l;
	size_t	r;

	if (dst && src)
	{
		r = ft_strlen(src);
		if (dstsize)
		{
			l = 0;
			while (src[l] && (dstsize > (l + 1)))
			{
				dst[l] = src[l];
				l++;
			}
			dst[l] = '\0';
		}
		return (r);
	}
	return (0);
}
