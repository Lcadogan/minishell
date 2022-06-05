/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:45:55 by acarmela          #+#    #+#             */
/*   Updated: 2021/04/18 21:32:47 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp_s;
	int		i;

	tmp_s = (char *)s;
	i = 0;
	while (tmp_s[i] != c)
	{
		if (tmp_s[i] == '\0')
			return (NULL);
		i++;
	}
	return (&tmp_s[i]);
}
