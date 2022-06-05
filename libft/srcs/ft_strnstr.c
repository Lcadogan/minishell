/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:37:35 by acarmela          #+#    #+#             */
/*   Updated: 2021/04/18 21:33:24 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	size_t	lh;
	size_t	ln;
	size_t	i;

	lh = ft_strlen(haystack);
	ln = ft_strlen(needle);
	h = (char *)haystack;
	i = 0;
	if (ln == 0)
		return (h);
	if (ln > lh || ln > len)
		return (NULL);
	while (i <= (lh - ln) && i <= (len - ln))
	{
		if (h[i] == needle[0])
			if ((ft_memcmp(&h[i], needle, ln) == 0))
				return (&h[i]);
		i++;
	}
	return (NULL);
}
