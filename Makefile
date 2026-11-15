# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#              #
#    Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CHECKER_NAME	= checker

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

COMMON_SRCS		= parse.c \
				  parse_utils.c \
				  ft_split.c \
				  stack_init.c \
				  disorder.c \
				  bench.c \
				  print_utils.c \
				  op_swap_push.c \
				  op_push.c \
				  op_rotate.c \
				  op_rev_rotate.c \
				  sort_small.c \
				  strat_simple.c \
				  strat_medium.c \
				  strat_complex.c \
				  strat_bounce_cost.c \
				  strat_bounce.c \
				  strat_adaptive.c

MANDATORY_SRCS	= main.c $(COMMON_SRCS)
BONUS_SRCS		= checker.c get_next_line.c $(COMMON_SRCS)

MANDATORY_OBJS	= $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) -o $(NAME)

bonus: $(CHECKER_NAME)

$(CHECKER_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(CHECKER_NAME)

%.o: %.c push_swap.h checker.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(CHECKER_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
