/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(const char *s, int fd)
{
	int	len;

	if (!s)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

void	ft_putnbr_fd(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (char)('0' + (n % 10));
	ft_putchar_fd(c, fd);
}

void	ft_putnbr_pad_fd(int n, int width, int fd)
{
	int		digits;
	long	tmp;

	digits = 0;
	if (n <= 0)
		digits = 1;
	tmp = n;
	if (tmp < 0)
		tmp = -tmp;
	while (tmp > 0)
	{
		digits++;
		tmp /= 10;
	}
	while (width > digits)
	{
		ft_putchar_fd(' ', fd);
		width--;
	}
	ft_putnbr_fd(n, fd);
}

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
}
