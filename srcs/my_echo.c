/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:18:56 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 22:19:03 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_flag(char *argv)
{
	int			i;

	i = 0;
	if ((argv && argv[i] == '-') && (argv[i + 1] == 'n'))
	{
		i++;
		while (argv[i])
		{
			if (argv[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	my_echo(char **argv)
{
	int			flag;
	int			i;

	i = 1;
	flag = is_flag(argv[1]);
	if (flag == 1)
		argv++;
	while (argv[i] != NULL)
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	if (!flag)
		printf("\n");
	return (EXIT_SUCCESS);
}
