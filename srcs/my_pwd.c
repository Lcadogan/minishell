/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:19:57 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 22:20:12 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	my_pwd(void)
{
	char	dir[3000];

	getcwd(dir, 3000);
	printf("%s\n", dir);
	return (EXIT_SUCCESS);
}