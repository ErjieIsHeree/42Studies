# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: exia <exia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 12:12:04 by exia              #+#    #+#              #
#    Updated: 2026/01/25 18:44:16 by exia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

## Compiler
COMPILER := cc
CFLAGS := -Wall -Werror -Wextra

## File
NAME := libft.a
AR := ar
ARFLAGS := rcs

## Source
TEST := test.c
SRCS := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c\
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
			ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
			ft_toupper.c ft_memchr.c ft_strdup.c ft_substr.c\
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
			ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS := $(SRCS:.c=.o)

## Delete
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
