# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: exia <exia@student.42madrid.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/03 18:30:11 by erjieishere       #+#    #+#              #
#    Updated: 2026/05/30 18:41:42 by exia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror -pthread
NAME := codexion

SRC := folder_of_my_choice/main.c \
		folder_of_my_choice/src/codexion.c folder_of_my_choice/src/codex_init.c folder_of_my_choice/src/codex_run.c folder_of_my_choice/src/codex_destroy.c folder_of_my_choice/src/sim_utils.c folder_of_my_choice/src/dongle_utils.c folder_of_my_choice/src/coder_utils.c \
		folder_of_my_choice/src/parser/parser.c \
		folder_of_my_choice/src/coder/coder.c folder_of_my_choice/src/coder/dongle_ops.c \
		folder_of_my_choice/src/coder/heap/edf_heap.c folder_of_my_choice/src/coder/heap/fifo_heap.c folder_of_my_choice/src/coder/heap/arr_utils.c

OBJS := $(SRC:.c=.o)

TEST_SRC := ignores/test.c


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

t: $(TEST_SRC)
	$(CC) $(TEST_SRC) -o $@

rt: $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $@

tc: $(TEST_SRC)
	rm -rf t

dbg: $(OBJS)
	gcc -fsanitize=address -g $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	find . -name "*.o" -type f -delete

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: test cleant all clean fclean re
