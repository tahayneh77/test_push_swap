/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack(t_stack *dst, t_stack *src)
{
	t_node	*node;

	if (!src || src->size == 0)
		return ;
	node = src->top;
	src->top = node->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	src->size--;
	node->prev = NULL;
	node->next = dst->top;
	if (dst->top)
		dst->top->prev = node;
	else
		dst->bottom = node;
	dst->top = node;
	dst->size++;
}

void	op_pa(t_stack *a, t_stack *b, t_bench *bench, int print)
{
	push_stack(a, b);
	if (bench && bench->enabled)
	{
		bench->pa++;
		bench->total_ops++;
	}
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	op_pb(t_stack *a, t_stack *b, t_bench *bench, int print)
{
	push_stack(b, a);
	if (bench && bench->enabled)
	{
		bench->pb++;
		bench->total_ops++;
	}
	if (print)
		ft_putstr_fd("pb\n", 1);
}
