# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: exia <exia@student.42madrid.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/06 17:40:11 by exia              #+#    #+#              #
#    Updated: 2026/02/12 13:44:27 by exia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- Variables ----------------------------------

# Compiler
CC := cc
CFLAGS := -Wall -Werror -Wextra -Iincludes

# File
NAME := push_swap
AR := ar
ARFLAGS := -rcs
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

# Sources
MAIN := main.c
BENCH_SRC := src/bench/select_strat.c src/bench/bench_start.c src/bench/print_bench.c
CHECKER_SRC := src/checker/checker.c src/checker/check_flags.c src/checker/checker_utils.c src/checker/is_number.c src/checker/check.c src/checker/append_node.c src/checker/parse_args.c
PUSH_SWAP_SRC := src/push_swap/execute_alg.c src/push_swap/free_funcs.c src/push_swap/strats.c src/push_swap/medium_f.c src/push_swap/medium_f2.c src/push_swap/utils.c src/push_swap/bits_functions.c src/push_swap/normalize_list.c
PUSH_SWAP_FUN_SRC := src/push_swap/moves/a_actions.c src/push_swap/moves/ab_actions.c src/push_swap/moves/b_actions.c src/push_swap/moves/movements.c
UTILS := utils/ft_lstnew_u.c utils/ft_lstsize_u.c utils/parse_int_str.c utils/is_str_number.c
OBJS := $(MAIN:.c=.o) $(BENCH_SRC:.c=.o) $(CHECKER_SRC:.c=.o) $(PUSH_SWAP_SRC:.c=.o) $(PUSH_SWAP_FUN_SRC:.c=.o) $(UTILS:.c=.o)
# Delete
CLEAN := rm
CLFLAGS := -f

#----------------------------------- Targets -----------------------------------

# Targets
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Programa creado"

$(LIBFT):
	make -C $(LIBFT_DIR)

clean: 
	$(CLEAN) $(CLFLAGS) $(OBJS) $(UTILS_OBJS) && make fclean -C $(LIBFT_DIR)
	@echo "Archivos .o y .a eliminados"

fclean: clean
	$(CLEAN) $(CLFLAGS) $(NAME)
	@echo "Archivos .o y NAME eliminados"

re: fclean
	make all

# Phony
.PHONY: all clean fclean re
