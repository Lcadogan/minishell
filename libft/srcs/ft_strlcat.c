/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 09:42:27 by acarmela          #+#    #+#             */
/*   Updated: 2020/11/07 18:01:59 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	len += i;
	if (!(dstsize == 0 || dstsize < ft_strlen(dst)))
	{
		while (i < (dstsize - 1) && src[0] != '\0')
		{
			dst[i] = (char)src[0];
			i++;
			src++;
		}
		dst[i] = '\0';
	}
	return (len);
}
