/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_init(t_bench *bench)
{
	if (!bench)
		return ;
	bench->enabled = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total_ops = 0;
	bench->disorder = 0.0;
	bench->strat = STRAT_ADAPTIVE;
	bench->regime = 0;
}

static void	bench_print_disorder(double disorder)
{
	long	pct;
	long	whole;
	long	frac;

	pct = (long)(disorder * 10000.0 + 0.5);
	whole = pct / 100;
	frac = pct % 100;
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putchar_fd('.', 2);
	if (frac < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(frac, 2);
	ft_putstr_fd("%\n", 2);
}

static void	bench_print_strat(t_bench *bench)
{
	ft_putstr_fd("[bench] strategy:   ", 2);
	if (bench->strat == STRAT_SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (bench->strat == STRAT_MEDIUM)
		ft_putstr_fd("Medium / O(n\xe2\x88\x9an)\n", 2);
	else if (bench->strat == STRAT_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
	{
		if (bench->regime == 0)
			ft_putstr_fd("Adaptive / O(n^2)\n", 2);
		else if (bench->regime == 1)
			ft_putstr_fd("Adaptive / O(n\xe2\x88\x9an)\n", 2);
		else
			ft_putstr_fd("Adaptive / O(n log n)\n", 2);
	}
}

static void	bench_print_counts(t_bench *b)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_pad_fd(b->sa, 3, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_pad_fd(b->sb, 3, 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putnbr_pad_fd(b->ss, 3, 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_pad_fd(b->pa, 3, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_pad_fd(b->pb, 3, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_pad_fd(b->ra, 3, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_pad_fd(b->rb, 3, 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_pad_fd(b->rr, 3, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_pad_fd(b->rra, 3, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_pad_fd(b->rrb, 3, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_pad_fd(b->rrr, 3, 2);
	ft_putchar_fd('\n', 2);
}

void	bench_print(t_bench *bench)
{
	if (!bench || !bench->enabled)
		return ;
	bench_print_disorder(bench->disorder);
	bench_print_strat(bench);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_putchar_fd('\n', 2);
	bench_print_counts(bench);
}
