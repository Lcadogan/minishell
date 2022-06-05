/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <acarmela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:28:03 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/24 12:25:05 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;
	size_t			i;

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (!n)
		return (1);
	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (s_1[i] != '\0' || s_2[i] != '\0'))
	{
		if (s_1[i] != s_2[i])
			return (s_1[i] - s_2[i]);
		i++;
	}
	return (0);
}
