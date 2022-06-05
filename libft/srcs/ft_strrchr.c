/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:04:53 by acarmela          #+#    #+#             */
/*   Updated: 2021/04/18 21:41:15 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp_s;
	int		i;

	tmp_s = (char *)s;
	i = ft_strlen(s);
	while (i != 0)
	{
		if (tmp_s[i] == c)
			return (tmp_s + i);
		i--;
	}
	if (tmp_s[i] == c)
		return (tmp_s + i);
	return (0);
}
