/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <acarmela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:43:11 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/24 12:27:37 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned char	*tmp;
	size_t			i;

	if (!s)
		return (0);
	tmp = (unsigned char *)s;
	i = 0;
	while (tmp[i] != '\0')
		i++;
	return (i);
}
