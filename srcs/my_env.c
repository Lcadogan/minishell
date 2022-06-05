/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:19:11 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 22:19:13 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	my_env(char **envp_cp, char **argv)
{
	int				count;

	count = count_arguments(argv);
	if (count > 1)
	{
		printf("env: ‘%s’: No such file or directory", argv[1]);
		return (127);
	}
	print_arr_2x(envp_cp);
	return (EXIT_SUCCESS);
}
