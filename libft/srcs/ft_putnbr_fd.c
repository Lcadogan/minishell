/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:51:05 by acarmela          #+#    #+#             */
/*   Updated: 2020/11/20 19:09:23 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 10)
	{
		write(fd, "1", 1);
		n = 0;
	}
	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		n = 8;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 10)
		ft_putnbr_fd(n / 10, fd);
	n = n % 10 + 48;
	ft_putchar_fd(n, fd);
}
