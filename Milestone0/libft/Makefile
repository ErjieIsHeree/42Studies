# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: exia <exia@student.42madrid.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 12:12:04 by exia              #+#    #+#              #
#    Updated: 2026/02/13 11:39:28 by exia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC := cc
CFLAGS := -Wall -Werror -Wextra
TFLAGS := -lbsd -g3

# File
NAME := libft.a
AR := ar
ARFLAGS := -rcs

# Source
TEST := test.c
SRCS := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
			ft_strlcpy.c ft_strlcat.c ft_tolower.c ft_strchr.c ft_strrchr.c\
			ft_strncmp.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
			ft_toupper.c ft_memchr.c ft_strdup.c ft_substr.c ft_strjoin.c\
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
			ft_lstmap.c
OBJS := $(SRCS:.c=.o)

# Delete
CLEAN := rm
CLFLAGS := -f


# Targets
all: $(NAME)

## Testing
t: $(TEST)
	$(CC) $(TFLAGS) $(TEST) -o t

t%: ft_%.c $(TEST)
	$(CC) $(CFLAGS) -c $< -o test.o
	$(CC) $(TFLAGS) $(TEST) test.o -o t

ta: $(OBJS) $(TEST)
	$(CC) $(TFLAGS) $(TEST) $< -o t

tc: fclean
	$(CLEAN) $(CLFLAGS) test.o t

## Base
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^
	@echo "Libreria creada"

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean: 
	$(CLEAN) $(CLFLAGS) $(OBJS)
	@echo "Archivos .o eliminados"

fclean: clean
	$(CLEAN) $(CLFLAGS) $(NAME)
	@echo "Archivos .o y .a eliminados"

re: fclean
	make all

# Phony
.PHONY: all test testo bonus clean fclean re
