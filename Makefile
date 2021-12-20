# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 17:36:57 by fcaquard          #+#    #+#              #
#    Updated: 2021/12/20 20:14:15 by fcaquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGCS = -Wall -Werror -Wextra
LIBS_PATH = ./libft/

NAME = push_swap

STRATEGIES_SRC = ./strategies/
PRE_SORT_SRC = ./pre_sort/
MANDATORY_SRC = ./moves/
SRCS = \
	push_swap.c						\
	stacks.c						\
	stacks_utils.c					\
	rewinders.c						\
	$(PRE_SORT_SRC)validation.c		\
	$(PRE_SORT_SRC)preparation.c	\
	clear.c							\
	____debug.c						\
	display.c						\
	# context.c						\
	# candidates.c					\
	# destination.c					\
	# navigate.c						\
	# routes.c						\
	# $(STRATEGIES_SRC)sort_big.c		\
	# $(STRATEGIES_SRC)sort_medium.c	\
	# $(STRATEGIES_SRC)sort_small.c	\
	# $(MANDATORY_SRC)pushy.c			\
	# $(MANDATORY_SRC)returny.c		\
	# $(MANDATORY_SRC)rreturny.c		\
	# $(MANDATORY_SRC)switchy.c		\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) makelibft
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBS_PATH) -lft -o $(CFLAGS) $(NAME)

clean:
	rm -f $(STRATEGIES_SRC)*.o $(PRE_SORT_SRC)*.o $(MANDATORY_SRC)*.o $(LIBS_PATH)*.o ./*.o

fclean: cleanlibft clean
	rm ./$(NAME)

re: fclean all

cleanlibft: 
	cd $(LIBS_PATH) && $(MAKE) fclean

makelibft: 
	cd $(LIBS_PATH) && $(MAKE)
