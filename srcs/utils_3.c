/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:22:00 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 22:22:02 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	try_find2(char *path, char **env, int *n, char **str)
{
	char	*old;
	size_t	i;

	i = -1;
	if (env[*n] != NULL)
	{
		while (env[*n][++i] != '=')
			;
		if (ft_strlen(path) == i)
			*str = ft_strdup(&(env[*n][++i]));
		else
			*str = ft_strdup("");
	}
	else
	{
		if (!ft_strncmp(path, "?", 1))
		{
			*str = ft_itoa(g_status);
			old = *str;
			*str = ft_strjoin(*str, &path[1]);
			free(old);
		}
		else
			*str = ft_strdup("");
	}
}

char	*try_find(char *path, char **env)
{
	size_t	i;
	int		m;
	int		n;
	char	*str;

	i = -1;
	m = -1;
	n = -1;
	if (!path)
		return (ft_strdup("$"));
	while (env[++n] && !(is_equal(path, env[n])))
		;
	try_find2(path, env, &n, &str);
	free(path);
	return (str);
}

void	make_null(char ***argv, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		(*argv)[i] = NULL;
		i++;
	}
}

void	clear_arr_2x(char **a)
{
	int	i;

	i = -1;
	while (a[++i])
		free(a[i]);
	free(a);
}

char	*find_binary(char *cmnd, char *paths)
{
	char		*path;
	char		**arr;
	char		**tmp;
	struct stat	buf;

	path = NULL;
	if (!cmnd || !paths)
		return (NULL);
	if (ft_strchr(cmnd, '/'))
		return (ft_strdup(cmnd));
	arr = ft_split(paths, ':');
	tmp = arr;
	cmnd = ft_strjoin("/", cmnd);
	while (*tmp)
	{
		path = ft_strjoin(*tmp, cmnd);
		if (stat(path, &buf) == 0)
			break ;
		free(path);
		path = NULL;
		tmp++;
	}
	free(cmnd);
	clear_arr_2x(arr);
	return (path);
}
