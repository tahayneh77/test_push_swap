/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_streq(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 == '\0' && *s2 == '\0');
}

int	exec_cmd(char *cmd, t_stack *a, t_stack *b)
{
	if (ft_streq(cmd, "sa\n"))
		op_sa(a, NULL, 0);
	else if (ft_streq(cmd, "sb\n"))
		op_sb(b, NULL, 0);
	else if (ft_streq(cmd, "ss\n"))
		op_ss(a, b, NULL, 0);
	else if (ft_streq(cmd, "pa\n"))
		op_pa(a, b, NULL, 0);
	else if (ft_streq(cmd, "pb\n"))
		op_pb(a, b, NULL, 0);
	else if (ft_streq(cmd, "ra\n"))
		op_ra(a, NULL, 0);
	else if (ft_streq(cmd, "rb\n"))
		op_rb(b, NULL, 0);
	else if (ft_streq(cmd, "rr\n"))
		op_rr(a, b, NULL, 0);
	else if (ft_streq(cmd, "rra\n"))
		op_rra(a, NULL, 0);
	else if (ft_streq(cmd, "rrb\n"))
		op_rrb(b, NULL, 0);
	else if (ft_streq(cmd, "rrr\n"))
		op_rrr(a, b, NULL, 0);
	else
		return (0);
	return (1);
}

static int	process_instructions(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!exec_cmd(line, a, b))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		status;

	a.top = NULL;
	a.bottom = NULL;
	a.size = 0;
	b.top = NULL;
	b.bottom = NULL;
	b.size = 0;
	status = parse_arguments(argc, argv, &a, NULL);
	if (status <= 0)
		return (status < 0);
	if (!process_instructions(&a, &b))
	{
		stack_clear(&a);
		stack_clear(&b);
		ft_print_error();
		return (1);
	}
	if (b.size == 0 && is_sorted(&a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (stack_clear(&a), stack_clear(&b), 0);
}
