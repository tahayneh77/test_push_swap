/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static const char	*parse_sign(const char *str, int *sign)
{
	*sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

long	ft_atol(const char *str, int *error)
{
	int		sign;
	long	res;
	int		digits;

	res = 0;
	digits = 0;
	str = parse_sign(str, &sign);
	while (ft_isdigit(*str))
	{
		digits++;
		res = res * 10 + (*str - '0');
		if ((sign == 1 && res > 2147483647L)
			|| (sign == -1 && (-res) < -2147483648L))
			*error = 1;
		str++;
	}
	if (digits == 0 || *str != '\0')
		*error = 1;
	return (res * sign);
}

void	free_str_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
