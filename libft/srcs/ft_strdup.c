/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <acarmela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:58:21 by acarmela          #+#    #+#             */
/*   Updated: 2021/07/29 16:21:29 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (0);
	ft_strlcpy(s2, s1, (len + 1));
	return (s2);
}
