/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(a))
		return ;
	first = a->top->idx;
	second = a->top->next->idx;
	third = a->top->next->next->idx;
	if (first > second && second < third && first < third)
		op_sa(a, bench, 1);
	else if (first > second && second > third)
	{
		op_sa(a, bench, 1);
		op_rra(a, bench, 1);
	}
	else if (first > second && second < third && first > third)
		op_ra(a, bench, 1);
	else if (first < second && second > third && first < third)
	{
		op_sa(a, bench, 1);
		op_ra(a, bench, 1);
	}
	else if (first < second && second > third && first > third)
		op_rra(a, bench, 1);
}

static void	push_min_to_b(t_stack *a, t_stack *b, t_bench *bench)
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
	op_pb(a, b, bench, 1);
}

static void	sort_five(t_stack *a, t_stack *b, t_bench *bench)
{
	while (a->size > 3)
		push_min_to_b(a, b, bench);
	sort_three(a, bench);
	while (b->size > 0)
		op_pa(a, b, bench, 1);
}

void	sort_small(t_stack *a, t_stack *b, t_bench *bench)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->top->idx > a->bottom->idx)
			op_sa(a, bench, 1);
	}
	else if (a->size == 3)
		sort_three(a, bench);
	else if (a->size <= 5)
		sort_five(a, b, bench);
}
