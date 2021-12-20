# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 17:36:57 by fcaquard          #+#    #+#              #
#    Updated: 2021/12/20 21:50:11 by fcaquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGCS = -Wall -Werror -Wextra
LIBS_PATH = ./libft/

NAME = push_swap

SMALL_SRC = ./sort_small/
MEDIUM_SRC = ./sort_medium/
BIG_SRC = ./sort_big/
MANDATORY_SRC = ./moves/
SRCS = \
	push_swap.c						\
	validation.c					\
	preparation.c					\
	stacks.c						\
	stacks_utils.c					\
	$(MANDATORY_SRC)px.c			\
	$(MANDATORY_SRC)rx.c			\
	$(MANDATORY_SRC)rrx.c			\
	$(MANDATORY_SRC)sx.c			\
	$(SMALL_SRC)sort_small.c		\
	$(MEDIUM_SRC)sort_medium.c		\
	$(BIG_SRC)sort_big.c			\
	$(BIG_SRC)context.c				\
	$(BIG_SRC)candidates.c			\
	$(BIG_SRC)destination.c			\
	$(BIG_SRC)navigate.c			\
	$(BIG_SRC)routes.c				\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) makelibft
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBS_PATH) -lft -o $(CFLAGS) $(NAME)

clean:
	rm -f $(STRATEGIES_SRC)*.o $(MANDATORY_SRC)*.o $(LIBS_PATH)*.o ./*.o

fclean: cleanlibft clean
	rm ./$(NAME)

re: fclean all

cleanlibft: 
	cd $(LIBS_PATH) && $(MAKE) fclean

makelibft: 
	cd $(LIBS_PATH) && $(MAKE)
