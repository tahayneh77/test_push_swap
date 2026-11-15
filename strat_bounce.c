/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_bounce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_simultaneous(t_stack *a, t_stack *b, int *c, t_bench *bench)
{
	while (c[0] > 0 && c[1] > 0)
	{
		op_rr(a, b, bench, 1);
		c[0]--;
		c[1]--;
	}
	while (c[0] < 0 && c[1] < 0)
	{
		op_rrr(a, b, bench, 1);
		c[0]++;
		c[1]++;
	}
}

static void	exec_rotations(t_stack *a, t_stack *b, int *c, t_bench *bench)
{
	exec_simultaneous(a, b, c, bench);
	while (c[0] > 0)
	{
		op_ra(a, bench, 1);
		c[0]--;
	}
	while (c[0] < 0)
	{
		op_rra(a, bench, 1);
		c[0]++;
	}
	while (c[1] > 0)
	{
		op_rb(b, bench, 1);
		c[1]--;
	}
	while (c[1] < 0)
	{
		op_rrb(b, bench, 1);
		c[1]++;
	}
	op_pb(a, b, bench, 1);
}

static void	push_back_to_sorted_a(t_stack *a, t_stack *b, t_bench *bench)
{
	int	target_idx;
	int	pos;

	while (b->size > 0)
	{
		target_idx = get_target_in_a(a, b->top->idx);
		pos = get_idx_position(a, target_idx);
		if (pos <= a->size / 2)
		{
			while (a->top->idx != target_idx)
				op_ra(a, bench, 1);
		}
		else
		{
			while (a->top->idx != target_idx)
				op_rra(a, bench, 1);
		}
		op_pa(a, b, bench, 1);
	}
}

static void	final_rotate_a(t_stack *a, t_bench *bench)
{
	int	pos;

	pos = get_idx_position(a, 0);
	if (pos <= a->size / 2)
	{
		while (a->top->idx != 0)
			op_ra(a, bench, 1);
	}
	else
	{
		while (a->top->idx != 0)
			op_rra(a, bench, 1);
	}
}

void	sort_bounce(t_stack *a, t_stack *b, t_bench *bench)
{
	int	costs[2];

	if (is_sorted(a))
		return ;
	if (a->size <= 5)
	{
		sort_small(a, b, bench);
		return ;
	}
	op_pb(a, b, bench, 1);
	if (a->size > 3)
		op_pb(a, b, bench, 1);
	while (a->size > 3)
	{
		find_cheapest_move(a, b, &costs[0], &costs[1]);
		exec_rotations(a, b, costs, bench);
	}
	sort_small(a, b, bench);
	push_back_to_sorted_a(a, b, bench);
	final_rotate_a(a, bench);
}
