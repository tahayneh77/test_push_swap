/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				val;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef enum e_strat
{
	STRAT_ADAPTIVE = 0,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strat;

typedef struct s_bench
{
	int		enabled;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total_ops;
	double	disorder;
	t_strat	strat;
	int		regime;
}	t_bench;

/* Operations */
void	op_sa(t_stack *a, t_bench *bench, int print);
void	op_sb(t_stack *b, t_bench *bench, int print);
void	op_ss(t_stack *a, t_stack *b, t_bench *bench, int print);
void	op_pa(t_stack *a, t_stack *b, t_bench *bench, int print);
void	op_pb(t_stack *a, t_stack *b, t_bench *bench, int print);
void	op_ra(t_stack *a, t_bench *bench, int print);
void	op_rb(t_stack *b, t_bench *bench, int print);
void	op_rr(t_stack *a, t_stack *b, t_bench *bench, int print);
void	op_rra(t_stack *a, t_bench *bench, int print);
void	op_rrb(t_stack *b, t_bench *bench, int print);
void	op_rrr(t_stack *a, t_stack *b, t_bench *bench, int print);

/* Parsing & Stack Init */
int		parse_arguments(int argc, char **argv, t_stack *a, t_bench *bench);
int		init_ranks(t_stack *a);
void	stack_clear(t_stack *s);
int		stack_push_bottom(t_stack *s, int val);

/* Utils */
int		ft_isdigit(int c);
int		ft_isspace(char c);
long	ft_atol(const char *str, int *error);
char	**ft_split_spaces(const char *str);
void	free_str_array(char **arr);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putnbr_fd(long n, int fd);
void	ft_putnbr_pad_fd(int n, int width, int fd);
void	ft_print_error(void);

/* Disorder & Sorting Helpers */
double	compute_disorder(t_stack *a);
int		is_sorted(t_stack *a);
int		find_min_idx(t_stack *s);
int		find_max_idx(t_stack *s);
int		get_idx_position(t_stack *s, int idx);

/* Strategies */
int		get_target_in_b(t_stack *b, int idx_a);
int		get_target_in_a(t_stack *a, int idx_b);
void	find_cheapest_move(t_stack *a, t_stack *b, int *best_a, int *best_b);
void	sort_small(t_stack *a, t_stack *b, t_bench *bench);
void	sort_simple(t_stack *a, t_stack *b, t_bench *bench);
void	sort_medium(t_stack *a, t_stack *b, t_bench *bench);
void	sort_complex(t_stack *a, t_stack *b, t_bench *bench);
void	sort_bounce(t_stack *a, t_stack *b, t_bench *bench);
void	sort_adaptive(t_stack *a, t_stack *b, t_bench *bench);

/* Benchmark */
void	bench_init(t_bench *bench);
void	bench_print(t_bench *bench);

#endif
