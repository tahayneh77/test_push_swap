/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_bounce_cost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target_in_b(t_stack *b, int idx_a)
{
	t_node	*curr;
	int		target_idx;

	target_idx = -1;
	curr = b->top;
	while (curr)
	{
		if (curr->idx < idx_a && (target_idx == -1 || curr->idx > target_idx))
			target_idx = curr->idx;
		curr = curr->next;
	}
	if (target_idx == -1)
		target_idx = find_max_idx(b);
	return (target_idx);
}

int	get_target_in_a(t_stack *a, int idx_b)
{
	t_node	*curr;
	int		target_idx;

	target_idx = -1;
	curr = a->top;
	while (curr)
	{
		if (curr->idx > idx_b && (target_idx == -1 || curr->idx < target_idx))
			target_idx = curr->idx;
		curr = curr->next;
	}
	if (target_idx == -1)
		target_idx = find_min_idx(a);
	return (target_idx);
}

static int	calc_cost_val(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

static int	calc_combo_cost(int ca, int cb)
{
	int	abs_a;
	int	abs_b;

	abs_a = ca;
	if (abs_a < 0)
		abs_a = -abs_a;
	abs_b = cb;
	if (abs_b < 0)
		abs_b = -abs_b;
	if (ca >= 0 && cb >= 0)
	{
		if (ca > cb)
			return (ca);
		return (cb);
	}
	if (ca <= 0 && cb <= 0)
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	return (abs_a + abs_b);
}

void	find_cheapest_move(t_stack *a, t_stack *b, int *best_a, int *best_b)
{
	t_node	*curr;
	int		pos_a;
	int		cost[2];
	int		min_cost;

	min_cost = 2147483647;
	pos_a = 0;
	curr = a->top;
	while (curr)
	{
		cost[0] = calc_cost_val(pos_a, a->size);
		cost[1] = calc_cost_val(get_idx_position(b,
					get_target_in_b(b, curr->idx)), b->size);
		if (calc_combo_cost(cost[0], cost[1]) < min_cost)
		{
			min_cost = calc_combo_cost(cost[0], cost[1]);
			*best_a = cost[0];
			*best_b = cost[1];
		}
		pos_a++;
		curr = curr->next;
	}
}
