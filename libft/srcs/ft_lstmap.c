/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <acarmela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:26:23 by acarmela          #+#    #+#             */
/*   Updated: 2021/04/27 12:03:41 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*res;

	if (lst && f && del)
	{
		new = NULL;
		while (lst)
		{
			res = ft_lstnew(f(lst->content));
			if (res == NULL)
			{
				ft_lstclear(&new, del);
				return (NULL);
			}
			ft_lstadd_back(&new, res);
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
