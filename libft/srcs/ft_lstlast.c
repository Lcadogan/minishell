/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:02:27 by acarmela          #+#    #+#             */
/*   Updated: 2020/11/20 10:30:59 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*a;

	if (lst == NULL)
		return (NULL);
	a = lst;
	while (a->next != NULL)
		a = a->next;
	return (a);
}
