/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *s)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!s || s->size < 2)
		return ;
	first = s->top;
	second = first->next;
	third = second->next;
	first->next = third;
	if (third)
		third->prev = first;
	else
		s->bottom = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	s->top = second;
}

void	op_sa(t_stack *a, t_bench *bench, int print)
{
	swap_stack(a);
	if (bench && bench->enabled)
	{
		bench->sa++;
		bench->total_ops++;
	}
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	op_sb(t_stack *b, t_bench *bench, int print)
{
	swap_stack(b);
	if (bench && bench->enabled)
	{
		bench->sb++;
		bench->total_ops++;
	}
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	op_ss(t_stack *a, t_stack *b, t_bench *bench, int print)
{
	swap_stack(a);
	swap_stack(b);
	if (bench && bench->enabled)
	{
		bench->ss++;
		bench->total_ops++;
	}
	if (print)
		ft_putstr_fd("ss\n", 1);
}
