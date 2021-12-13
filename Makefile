# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 17:36:57 by fcaquard          #+#    #+#              #
#    Updated: 2021/12/13 13:49:46 by fcaquard         ###   ########.fr        #
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
	debug.c							\
	preparation.c					\
	push_swap.c						\
	validation.c					\

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


# gcc *.c && valgrind --leak-check=full ./a.out
# gcc -Wall -Werror -Wextra _libft/*.c strategies/*.c mandatory_functions/*.c *.c && valgrind --leak-check=full ./a.out 1 2 3 4 5 6 7 8 9 -2147483648
# gcc -Wall -Werror -Wextra -fsanitize=address _libft/*.c strategies/*.c mandatory_functions/*.c *.c  &&  ./a.out 1 2 3 4 5 6 7 8 9 -2147483648

# make
# gcc -Wall -Werror -Wextra strategies/*.c mandatory_functions/*.c *.c libft/libft.a &&  ./a.out 4 7 6 1 8 9 0 3 2 5
 

# DEBUG -- NO FLAG
#10OK# 		gcc strategies/*.c mandatory_functions/*.c *.c libft/libft.a &&  ./a.out 601206884 1650000653 -436741934 -720342231 -522312740 68924413 -962224530 -1181434586 1154398132 -721309158

#10OK# 		gcc -Wall -Werror -Wextra strategies/*.c mandatory_functions/*.c *.c libft/libft.a &&  ./a.out 601206884 1650000653 -436741934 -720342231 -522312740 68924413 -962224530 -1181434586 1154398132 -721309158
#10FAIL#	gcc -Wall -Werror -Wextra strategies/*.c mandatory_functions/*.c *.c libft/libft.a &&  ./a.out 601206884 1650000653 -436741934 -720342231 -522312740 68924413 -962224530 -1181434586 1154398132 -721309158 681395076 1516687826 -1719446151 -815545832 -1399600689 383829031 -1615975253 93614517 192016385 1137558331
#100FAIL# 	gcc -Wall -Werror -Wextra strategies/*.c mandatory_functions/*.c *.c libft/libft.a &&  ./a.out 601206884 1650000653 -436741934 -720342231 -522312740 68924413 -962224530 -1181434586 1154398132 -721309158 681395076 1516687826 -1719446151 -815545832 -1399600689 383829031 -1615975253 93614517 192016385 1137558331 -578713953 -717877604 -1089698334 -2117187486 -523529124 618138689 -846975242 239509830 1629217763 -730128316 761515023 -2044245488 -360934656 -1802260646 762258073 -1313563464 -395329928 -564695782 1735402795 -990758167 -659541449 163054565 -1443830721 17115532 -514846411 -1076043839 -1033214459 -1890559587 1580552176 -466597842 1548486842 -1255706840 -1119967316 1711603353 -1762202507 185988629 -1774430623 -1342885702 -906222477 684120438 2095782810 1434945373 141816211 394047317 -656677781 598551098 -1081566357 -276383701 1294914581 1155087381 2053126238 -1258180617 1389619053 471900662 -342287260 1631584932 594725458 -957044833 -479926377 1398570342 -75832146 -247457893 1595661300 -976171879 112498262 1533779400 1987035600 899710383 -1447245606 912116468 -2015076228 -6071407 347573190 1671182249 -1638236787 -1609821422 -1014518955 -1601205636 1996493332 -203773803

#  gcc -Wall -Werror -Wextra strategies/*.c mandatory_functions/*.c *.c libft/libft.a &&  ./a.out 6 3 0 4 8 5 7 9 1 2
#  gcc strategies/*.c mandatory_functions/*.c *.c libft/libft.a &&  ./a.out 5 4 3 1 6 0 7 8 2 9

# VALGRIND
#10OK# 		gcc -Wall -Werror -Wextra strategies/*.c mandatory_functions/*.c *.c libft/libft.a &&  valgrind --leak-check=yes ./a.out 601206884 1650000653 -436741934 -720342231 -522312740 68924413 -962224530 -1181434586 1154398132 -721309158