/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <acarmela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:01:22 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/24 12:24:29 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_start(char const *s1, char const *set)
{
	size_t		j;
	int			flag1;
	size_t		i;
	char		*s_1;
	char		*s_et;

	s_1 = (char *)s1;
	s_et = (char *)set;
	i = 0;
	while (i < ft_strlen(s1))
	{
		flag1 = 0;
		j = ft_strlen(set);
		while (j--)
		{
			if (s_1[i] == s_et[j])
				flag1 += 1;
		}
		if (flag1 != 0)
			i++;
		else
			return (i);
	}
	return (i);
}

static size_t	ft_finish(char const *s1, char const *set)
{
	size_t		j;
	int			flag1;
	size_t		i;
	char		*s_1;
	char		*s_et;

	s_1 = (char *)s1;
	s_et = (char *)set;
	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		flag1 = 0;
		j = ft_strlen(set);
		while (j--)
		{
			if (s_1[i] == s_et[j])
				flag1 += 1;
		}
		if (flag1 != 0)
			i--;
		else
			return (i);
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		finish;
	char		*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (ft_strlen(s1) == 0 || ft_strlen(set) == 0)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	start = ft_start(s1, set);
	finish = ft_finish(s1, set);
	if (start > finish)
		return (res = ft_strdup(""));
	else
		res = ft_substr(s1, start, finish - start + 1);
	return (res);
}
