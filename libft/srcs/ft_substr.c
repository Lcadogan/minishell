/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <acarmela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 09:05:07 by acarmela          #+#    #+#             */
/*   Updated: 2021/04/27 09:56:25 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_memory(char *res, int i)
{
	res = malloc(sizeof(char) * i);
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*res;

	res = NULL;
	if (s == NULL)
		return (NULL);
	if (len < 0)
		return (NULL);
	if (start > ft_strlen(s))
		ft_memory(res, 1);
	n = ft_strlen(s) - (size_t)start;
	if (n < len)
		(len = n);
	ft_memory(res, len + 1);
	ft_memcpy(res, &s[start], len);
	res[len] = '\0';
	return (res);
}
