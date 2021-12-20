# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 17:36:57 by fcaquard          #+#    #+#              #
#    Updated: 2021/12/20 12:08:39 by fcaquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGCS = -Wall -Werror -Wextra
LIBS_PATH = ./libft/

NAME = push_swap

STRATEGIES_SRC = ./strategies/
MANDATORY_SRC = ./mandatory_functions/
SRCS = \
	$(STRATEGIES_SRC)sort_above.c	\
	$(STRATEGIES_SRC)sort_five.c	\
	$(STRATEGIES_SRC)sort_three.c	\
	$(MANDATORY_SRC)pushy.c			\
	$(MANDATORY_SRC)returny.c		\
	$(MANDATORY_SRC)rreturny.c		\
	$(MANDATORY_SRC)switchy.c		\
	list_utils.c					\
	lists.c							\
	preparation.c					\
	push_swap.c						\
	validation.c					\
	context.c						\
	candidates.c					\
	destination.c					\
	radar.c							\
	clear.c							\
	display.c						\
	debug.c							\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) makelibft
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBS_PATH) -lft -o $(NAME)

clean:
	rm -f $(STRATEGIES_SRC)*.o $(MANDATORY_SRC)*.o $(LIBS_PATH)*.o ./*.o

fclean: cleanlibft clean
	rm ./$(NAME)

re: fclean all

cleanlibft: 
	cd $(LIBS_PATH) && $(MAKE) fclean

makelibft: 
	cd $(LIBS_PATH) && $(MAKE)
