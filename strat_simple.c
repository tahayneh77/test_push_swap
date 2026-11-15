/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_min_to_top_a(t_stack *a, t_bench *bench)
{
	int	min_idx;
	int	pos;

	min_idx = find_min_idx(a);
	pos = get_idx_position(a, min_idx);
	if (pos <= a->size / 2)
	{
		while (a->top->idx != min_idx)
			op_ra(a, bench, 1);
	}
	else
	{
		while (a->top->idx != min_idx)
			op_rra(a, bench, 1);
	}
}

void	sort_simple(t_stack *a, t_stack *b, t_bench *bench)
{
	if (is_sorted(a))
		return ;
	if (a->size <= 5)
	{
		sort_small(a, b, bench);
		return ;
	}
	while (a->size > 3)
	{
		bring_min_to_top_a(a, bench);
		op_pb(a, b, bench, 1);
	}
	sort_small(a, b, bench);
	while (b->size > 0)
		op_pa(a, b, bench, 1);
}
