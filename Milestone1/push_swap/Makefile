# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/06 17:40:11 by exia              #+#    #+#              #
#    Updated: 2026/02/06 20:29:55 by smarin-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- Variables ----------------------------------

# Compiler
COMPILER := cc
CFLAGS := -Wall -Werror -Iincludes #-Wextra 

# File
NAME := push_swap
AR := ar
ARFLAGS := -rcs

# Sources
MAIN := main.c
LIBFT_SRC := libft/sum.c libft/ft_printf.c libft/ft_putunsnbr.c libft/ft_putnbr.c libft/ft_putstr.c libft/ft_putchar.c libft/ft_lstnew.c libft/ft_strcmp.c libft/ft_calloc.c  libft/ft_atoi.c
BENCH_SRC := src/bench/bench_parse.c
CHECKER_SRC := src/checker/checker.c src/checker/check_strat.c
PARSE_SRC := src/parse/parse.c
PUSH_SWAP_SRC := src/push_swap/push_swap.c
UTILS := 
OBJS := $(MAIN:.c=.o) $(LIBFT_SRC:.c=.o) $(BENCH_SRC:.c=.o) $(CHECKER_SRC:.c=.o) $(PARSE_SRC:.c=.o) $(PUSH_SWAP_SRC:.c=.o) $(UTILS:.c=.o)

# Delete
CLEAN := rm
CLFLAGS := -f

#----------------------------------- Targets -----------------------------------

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "Programa creado"

clean: 
	$(CLEAN) $(CLFLAGS) $(OBJS) $(UTILS_OBJS)
	@echo "Archivos .o eliminados"

fclean: clean
	$(CLEAN) $(CLFLAGS) $(NAME)
	@echo "Archivos .o y .a eliminados"

re: fclean all

# Phony
.PHONY: all test testw testo testow clean fclean re
