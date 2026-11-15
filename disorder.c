/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	long	mistakes;
	long	total_pairs;
	t_node	*curr_i;
	t_node	*curr_j;

	if (!a || a->size <= 1)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	curr_i = a->top;
	while (curr_i)
	{
		curr_j = curr_i->next;
		while (curr_j)
		{
			total_pairs++;
			if (curr_i->val > curr_j->val)
				mistakes++;
			curr_j = curr_j->next;
		}
		curr_i = curr_i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

int	is_sorted(t_stack *a)
{
	t_node	*curr;

	if (!a || a->size <= 1)
		return (1);
	curr = a->top;
	while (curr->next)
	{
		if (curr->val > curr->next->val)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	find_min_idx(t_stack *s)
{
	t_node	*curr;
	int		min;

	if (!s || !s->top)
		return (0);
	min = s->top->idx;
	curr = s->top->next;
	while (curr)
	{
		if (curr->idx < min)
			min = curr->idx;
		curr = curr->next;
	}
	return (min);
}

int	find_max_idx(t_stack *s)
{
	t_node	*curr;
	int		max;

	if (!s || !s->top)
		return (0);
	max = s->top->idx;
	curr = s->top->next;
	while (curr)
	{
		if (curr->idx > max)
			max = curr->idx;
		curr = curr->next;
	}
	return (max);
}

int	get_idx_position(t_stack *s, int idx)
{
	t_node	*curr;
	int		pos;

	if (!s)
		return (0);
	pos = 0;
	curr = s->top;
	while (curr)
	{
		if (curr->idx == idx)
			return (pos);
		pos++;
		curr = curr->next;
	}
	return (0);
}
