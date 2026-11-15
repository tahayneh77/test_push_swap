/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_push_bottom(t_stack *s, int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->val = val;
	node->idx = 0;
	node->next = NULL;
	node->prev = s->bottom;
	if (s->bottom)
		s->bottom->next = node;
	else
		s->top = node;
	s->bottom = node;
	s->size++;
	return (1);
}

void	stack_clear(t_stack *s)
{
	t_node	*curr;
	t_node	*next;

	if (!s)
		return ;
	curr = s->top;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}

static void	sort_int_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_node_ranks(t_stack *a, int *arr)
{
	t_node	*curr;
	int		i;

	curr = a->top;
	while (curr)
	{
		i = 0;
		while (i < a->size)
		{
			if (arr[i] == curr->val)
			{
				curr->idx = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
}

int	init_ranks(t_stack *a)
{
	int		*arr;
	t_node	*c;
	int		i;

	if (!a || a->size <= 0)
		return (1);
	arr = (int *)malloc(sizeof(int) * a->size);
	if (!arr)
		return (0);
	c = a->top;
	i = 0;
	while (c)
	{
		arr[i++] = c->val;
		c = c->next;
	}
	sort_int_array(arr, a->size);
	i = 0;
	while (i < a->size - 1 && arr[i] != arr[i + 1])
		i++;
	if (i < a->size - 1)
		return (free(arr), 0);
	assign_node_ranks(a, arr);
	free(arr);
	return (1);
}
