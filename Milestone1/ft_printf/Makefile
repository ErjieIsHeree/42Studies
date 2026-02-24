# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: exia <exia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 12:12:04 by exia              #+#    #+#              #
#    Updated: 2026/01/27 15:12:55 by exia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
COMPILER := cc
CFLAGS := -Wall -Werror -Wextra

# File
NAME := libftprintf.a
AR := ar
ARFLAGS := rcs

# Source
TEST := test.c
SRCS := ft_printf.c put_functions.c
UTILS := utils.c
OBJS := $(SRCS:.c=.o)
UTILS_OBJS := $(UTILS:.c=.o)

# Delete
CLEAN := rm
CLFLAGS := -f


# Targets
all: $(NAME)

## Testing
test: $(TEST) $(SRCS) $(UTILS)
	$(COMPILER) $(CFLAGS) $^ -g

testw: $(TEST) $(SRCS) $(UTILS)
	$(COMPILER) $(CFLAGS) $^ -g -w

testo: $(TEST) #$(wildcard *) # REMOVE WILDCARD BEFORE EVALUATING
	$(COMPILER) $(CFLAGS) $^ -g

testow: $(TEST) #$(wildcard *) # REMOVE WILDCARD BEFORE EVALUATING
	$(COMPILER) $(CFLAGS) $^ -g -w

## Base
$(NAME): $(OBJS) $(UTILS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^
	@echo "Libreria creada"

clean: 
	$(CLEAN) $(CLFLAGS) $(OBJS) $(UTILS_OBJS)
	@echo "Archivos .o eliminados"

fclean: clean
	$(CLEAN) $(CLFLAGS) $(NAME)
	@echo "Archivos .o y .a eliminados"

re: fclean all

# Phony
.PHONY: all test testw testo testow clean fclean re