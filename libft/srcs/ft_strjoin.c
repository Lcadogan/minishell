/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:20:45 by acarmela          #+#    #+#             */
/*   Updated: 2020/11/14 17:18:15 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	n;
	size_t	m;
	char	*res;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	n = ft_strlen(s1);
	m = n + ft_strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * m);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, n + 1);
	ft_strlcat(res, s2, m);
	return (res);
}
