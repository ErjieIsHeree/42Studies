# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/03 18:30:11 by erjieishere       #+#    #+#              #
#    Updated: 2026/05/14 22:32:55 by erjieishere      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror -pthread
NAME := codexion

SRC := folder_of_my_choice/main.c \
		folder_of_my_choice/src/codexion.c folder_of_my_choice/src/codex_init.c folder_of_my_choice/src/codex_run.c folder_of_my_choice/src/codex_destroy.c folder_of_my_choice/src/creation_error.c \
		folder_of_my_choice/src/rules/get_rules.c folder_of_my_choice/src/rules/parse_data.c folder_of_my_choice/src/rules/validate_data.c \
		folder_of_my_choice/src/coder/codex.c folder_of_my_choice/src/coder/get_dongles.c \
		folder_of_my_choice/src/coder/heap/heap.c

OBJS := $(SRC:.c=.o)

TEST_SRC := ignores/test.c


$(NAME): $(SRC) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

test: $(TEST_SRC)
	$(CC) $(TEST_SRC) -o $@

tclean:
	rm -rf test

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	find . -name "*.o" -type f -delete

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: test cleant all clean fclean re
