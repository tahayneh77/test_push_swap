/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	b->top = NULL;
	b->bottom = NULL;
	b->size = 0;
}

static void	run_strategy(t_stack *a, t_stack *b, t_bench *bench)
{
	if (bench->strat == STRAT_SIMPLE)
		sort_simple(a, b, bench);
	else if (bench->strat == STRAT_MEDIUM)
		sort_medium(a, b, bench);
	else if (bench->strat == STRAT_COMPLEX)
		sort_complex(a, b, bench);
	else
		sort_adaptive(a, b, bench);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_bench	bench;
	int		status;

	init_stacks(&a, &b);
	bench_init(&bench);
	status = parse_arguments(argc, argv, &a, &bench);
	if (status <= 0)
	{
		if (status < 0)
			return (1);
		return (0);
	}
	bench.disorder = compute_disorder(&a);
	if (!is_sorted(&a))
		run_strategy(&a, &b, &bench);
	if (bench.enabled)
		bench_print(&bench);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
