# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: exia <exia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 12:12:04 by exia              #+#    #+#              #
#    Updated: 2026/01/25 18:42:45 by exia             ###   ########.fr        #
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
SRCS := 
OBJS := $(SRCS:.c=.o)

# Delete
CLEAN := rm
CLFLAGS := -f


# Targets
all: $(NAME)

## Testing
test: $(TEST) $(SRCS)
	$(COMPILER) $(CFLAGS) $^ -lbsd -g

testo: $(TEST)
	$(COMPILER) $(CFLAGS) $^

## Base
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "Libreria creada"

clean: 
	$(CLEAN) $(CLFLAGS) $(OBJS)
	@echo "Archivos .o eliminados"

fclean: clean
	$(CLEAN) $(CLFLAGS) $(NAME)
	@echo "Archivos .o y .a eliminados"

re: fclean all

# Phony
.PHONY: all test testo $(NAME) clean fclean re