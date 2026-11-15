/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s || s->size < 2)
		return ;
	first = s->top;
	second = first->next;
	s->top = second;
	second->prev = NULL;
	s->bottom->next = first;
	first->prev = s->bottom;
	first->next = NULL;
	s->bottom = first;
}

void	op_ra(t_stack *a, t_bench *bench, int print)
{
	rotate_stack(a);
	if (bench && bench->enabled)
	{
		bench->ra++;
		bench->total_ops++;
	}
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	op_rb(t_stack *b, t_bench *bench, int print)
{
	rotate_stack(b);
	if (bench && bench->enabled)
	{
		bench->rb++;
		bench->total_ops++;
	}
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	op_rr(t_stack *a, t_stack *b, t_bench *bench, int print)
{
	rotate_stack(a);
	rotate_stack(b);
	if (bench && bench->enabled)
	{
		bench->rr++;
		bench->total_ops++;
	}
	if (print)
		ft_putstr_fd("rr\n", 1);
}
