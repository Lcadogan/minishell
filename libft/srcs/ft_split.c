/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <acarmela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:22:57 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/24 13:23:51 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	**mycopy(char **spl, char *s, char c, int n)
{
	int	i;
	int	count;
	int	m;

	i = 0;
	count = 0;
	while (s[i] != '\0' && count < n)
	{
		m = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			spl[count][m] = s[i];
			i++;
			m++;
		}
		spl[count][m] = '\0';
		count++;
	}
	spl[count] = NULL;
	return (spl);
}

static char	**myfree(char **spl, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(spl[i]);
		i++;
	}
	free(spl);
	return (spl);
}

static char	**stroki(char **spl, int n, char c, char *str)
{
	int	m;
	int	j;

	j = 0;
	while (*str)
	{
		m = 0;
		while (*str == c)
			str++;
		while (*str != c && *str != '\0')
		{
			str++;
			m++;
		}
		if (m != 0)
		{
			spl[j] = (char *)malloc(sizeof(char) * (m + 1));
			if (!spl[j])
				return (myfree(spl, n));
		}
		j++;
	}
	return (spl);
}

static int	words(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**spl;

	if (!s)
		return (NULL);
	n = words((char *)s, c);
	spl = (char **)malloc(sizeof(char *) * (n + 1));
	if (!spl)
		return (NULL);
	spl = stroki(spl, n, c, (char *)s);
	spl = mycopy(spl, (char *)s, c, n);
	return (spl);
}
