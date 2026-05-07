# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/03 18:30:11 by erjieishere       #+#    #+#              #
#    Updated: 2026/05/07 12:02:27 by erjieishere      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror -pthread
NAME := codexion

SRC := main.c \
		src/codexion.c src/codex_init.c src/codex_destroy.c \
		src/rules/get_rules.c src/rules/parse_data.c src/rules/validate_data.c \
		src/coder/codex.c
OBJS := $(SRC:.c=.o)

TEST_SRC := ignores/test.c


$(NAME): $(SRC) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

test: $(TEST_SRC)
	$(CC) $(TEST_SRC)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	find . -name "*.o" -type f -delete

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
