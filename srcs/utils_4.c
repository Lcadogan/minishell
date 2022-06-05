/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:22:09 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 22:22:11 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	is_minishell(char *line)
{
	if (line == NULL || *line == '\0')
		return (0);
	if (!ft_strcmp(line, "./minishell"))
		return (1);
	return (0);
}

char	**copy_env(char **env)
{
	char	**dst;
	int		n;

	dst = NULL;
	n = 0;
	while (env[n])
		n++;
	dst = (char **)malloc(sizeof(char *) * (n + 1));
	n = 0;
	while (env[n])
	{
		dst[n] = ft_strdup(env[n]);
		n++;
	}
	dst[n] = NULL;
	return (dst);
}

char	*increase_sh_level(char *value)
{
	char	*number;
	char	*shlvl;
	int		level;

	if (!is_number(value))
		return (ft_strdup("SHLVL=1"));
	level = ft_atoi(value);
	if (level >= 999)
		return (ft_strdup("SHLVL="));
	if (level < 0)
		return (ft_strdup("SHLVL=0"));
	number = ft_itoa(++level);
	shlvl = ft_strjoin("SHLVL=", number);
	free(number);
	return (shlvl);
}

char	**add_default_variables(char ***envp)
{
	char	**tmp_arr;
	char	*tmp_str;
	int		i;
	char	*key;

	tmp_arr = ft_calloc(4, sizeof(char *));
	tmp_arr[0] = ft_strdup("OLDPWD=");
	tmp_str = getcwd(NULL, 0);
	tmp_arr[1] = ft_strjoin("PWD=", tmp_str);
	tmp_arr[2] = increase_sh_level(get_value(*envp, "SHLVL"));
	i = 0;
	while (tmp_arr[i] != NULL)
	{
		key = check_arg(*envp, &tmp_arr[i]);
		if (key)
			replace_var(key, *envp, tmp_arr[i]);
		else
			add_to_envp(envp, tmp_arr[i]);
		i++;
	}
	free(tmp_str);
	free(tmp_arr[0]);
	free(tmp_arr[1]), free(tmp_arr[2]);
	free(tmp_arr[3]), free(tmp_arr);
	return (*envp);
}
