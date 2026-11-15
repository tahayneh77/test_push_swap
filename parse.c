/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static int	parse_flag(const char *arg, t_bench *bench)
{
	if (!bench)
		return (0);
	if (ft_strcmp(arg, "--simple") == 0)
		bench->strat = STRAT_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		bench->strat = STRAT_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		bench->strat = STRAT_COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		bench->strat = STRAT_ADAPTIVE;
	else if (ft_strcmp(arg, "--bench") == 0)
		bench->enabled = 1;
	else
		return (0);
	return (1);
}

static int	parse_tokens(char **tokens, t_stack *a)
{
	int		j;
	int		err;
	long	val;

	if (!tokens || !tokens[0])
		return (0);
	j = 0;
	while (tokens[j])
	{
		err = 0;
		val = ft_atol(tokens[j], &err);
		if (err || !stack_push_bottom(a, (int)val))
			return (0);
		j++;
	}
	return (1);
}

static int	parse_single_arg(const char *arg, t_stack *a, t_bench *bench)
{
	char	**tokens;

	if (arg[0] == '-' && arg[1] == '-')
	{
		if (!parse_flag(arg, bench))
			return (0);
		return (1);
	}
	tokens = ft_split_spaces(arg);
	if (!tokens || !tokens[0])
	{
		free_str_array(tokens);
		return (0);
	}
	if (!parse_tokens(tokens, a))
	{
		free_str_array(tokens);
		return (0);
	}
	free_str_array(tokens);
	return (1);
}

int	parse_arguments(int argc, char **argv, t_stack *a, t_bench *bench)
{
	int	i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!parse_single_arg(argv[i], a, bench))
		{
			stack_clear(a);
			ft_print_error();
			return (-1);
		}
		i++;
	}
	if (a->size == 0)
		return (0);
	if (!init_ranks(a))
	{
		stack_clear(a);
		ft_print_error();
		return (-1);
	}
	return (1);
}
