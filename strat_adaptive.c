/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_adaptive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack *a, t_stack *b, t_bench *bench)
{
	if (is_sorted(a))
		return ;
	if (bench->disorder < 0.2)
		bench->regime = 0;
	else if (bench->disorder < 0.5)
		bench->regime = 1;
	else
		bench->regime = 2;
	if (a->size <= 5)
	{
		sort_small(a, b, bench);
		return ;
	}
	if (bench->regime == 0)
		sort_simple(a, b, bench);
	else if (bench->regime == 1)
		sort_medium(a, b, bench);
	else
		sort_bounce(a, b, bench);
}
