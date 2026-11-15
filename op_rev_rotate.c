/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_stack(t_stack *s)
{
	t_node	*last;
	t_node	*prev;

	if (!s || s->size < 2)
		return ;
	last = s->bottom;
	prev = last->prev;
	s->bottom = prev;
	prev->next = NULL;
	last->prev = NULL;
	last->next = s->top;
	s->top->prev = last;
	s->top = last;
}

void	op_rra(t_stack *a, t_bench *bench, int print)
{
	rev_rotate_stack(a);
	if (bench && bench->enabled)
	{
		bench->rra++;
		bench->total_ops++;
	}
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	op_rrb(t_stack *b, t_bench *bench, int print)
{
	rev_rotate_stack(b);
	if (bench && bench->enabled)
	{
		bench->rrb++;
		bench->total_ops++;
	}
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	op_rrr(t_stack *a, t_stack *b, t_bench *bench, int print)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
	if (bench && bench->enabled)
	{
		bench->rrr++;
		bench->total_ops++;
	}
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
