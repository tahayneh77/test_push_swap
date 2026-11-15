/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_bits;
	int	max_val;

	max_bits = 0;
	max_val = size - 1;
	while (max_val > 0)
	{
		max_bits++;
		max_val >>= 1;
	}
	return (max_bits);
}

static void	radix_pass(t_stack *a, t_stack *b, int bit, t_bench *bench)
{
	int	count;
	int	j;

	count = a->size;
	j = 0;
	while (j < count)
	{
		if (((a->top->idx >> bit) & 1) == 1)
			op_ra(a, bench, 1);
		else
			op_pb(a, b, bench, 1);
		j++;
	}
	while (b->size > 0)
		op_pa(a, b, bench, 1);
}

void	sort_complex(t_stack *a, t_stack *b, t_bench *bench)
{
	int	max_bits;
	int	bit;

	if (is_sorted(a))
		return ;
	if (a->size <= 5)
	{
		sort_small(a, b, bench);
		return ;
	}
	max_bits = get_max_bits(a->size);
	bit = 0;
	while (bit < max_bits)
	{
		radix_pass(a, b, bit, bench);
		if (is_sorted(a))
			break ;
		bit++;
	}
}
