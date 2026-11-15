/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_sqrt(int n)
{
	int	res;

	if (n <= 0)
		return (1);
	res = 1;
	while (res * res <= n)
		res++;
	return (res - 1);
}

static int	find_chunk_positions(t_stack *a, int max_idx, int *top, int *bot)
{
	t_node	*curr;
	int		pos;

	*top = -1;
	*bot = -1;
	pos = 0;
	curr = a->top;
	while (curr)
	{
		if (curr->idx <= max_idx)
		{
			if (*top == -1)
				*top = pos;
			*bot = pos;
		}
		pos++;
		curr = curr->next;
	}
	return (*top != -1);
}

static void	push_back_to_a(t_stack *a, t_stack *b, t_bench *bench)
{
	int	max_idx;
	int	pos;

	while (b->size > 0)
	{
		max_idx = find_max_idx(b);
		pos = get_idx_position(b, max_idx);
		if (pos <= b->size / 2)
		{
			while (b->top->idx != max_idx)
				op_rb(b, bench, 1);
		}
		else
		{
			while (b->top->idx != max_idx)
				op_rrb(b, bench, 1);
		}
		op_pa(a, b, bench, 1);
	}
}

static void	push_chunks_to_b(t_stack *a, t_stack *b, int chunk, t_bench *bench)
{
	int	max_idx;
	int	top_pos;
	int	bot_pos;

	max_idx = chunk - 1;
	while (a->size > 0)
	{
		while (find_chunk_positions(a, max_idx, &top_pos, &bot_pos))
		{
			if (a->top->idx <= max_idx)
			{
				op_pb(a, b, bench, 1);
				if (b->size > 1 && b->top->idx < max_idx - (chunk / 2))
					op_rb(b, bench, 1);
			}
			else if (top_pos <= (a->size - bot_pos))
				op_ra(a, bench, 1);
			else
				op_rra(a, bench, 1);
		}
		max_idx += chunk;
	}
}

void	sort_medium(t_stack *a, t_stack *b, t_bench *bench)
{
	int	chunk_size;

	if (is_sorted(a))
		return ;
	if (a->size <= 5)
	{
		sort_small(a, b, bench);
		return ;
	}
	chunk_size = get_sqrt(a->size);
	push_chunks_to_b(a, b, chunk_size, bench);
	push_back_to_a(a, b, bench);
}
