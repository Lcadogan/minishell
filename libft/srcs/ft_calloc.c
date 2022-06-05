/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:58:46 by acarmela          #+#    #+#             */
/*   Updated: 2020/11/14 15:31:25 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*c;

	c = malloc(count * size);
	if (c == NULL)
		return (NULL);
	ft_bzero(c, count * size);
	return (c);
}
