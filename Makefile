# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 17:36:57 by fcaquard          #+#    #+#              #
#    Updated: 2021/11/24 12:01:43 by fcaquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# gcc *.c && valgrind --leak-check=full ./a.out

# gcc -Wall -Werror -Wextra _libft/*.c strategies/*.c mandatory_functions/*.c *.c && valgrind --leak-check=full ./a.out 1 2 3 4 5 6 7 8 9 -2147483648


# gcc -Wall -Werror -Wextra -fsanitize=address _libft/*.c strategies/*.c mandatory_functions/*.c *.c  &&  ./a.out 1 2 3 4 5 6 7 8 9 -2147483648


# make
# gcc -Wall -Werror -Wextra strategies/*.c mandatory_functions/*.c *.c  &&  ./a.out 1 205550 8 9 -2147483648
 

CC = cc
CFLAGCS = -Wall -Werror -Wextra
LIBS_PATH = ./libft/

 all:  makelib

 makelib: 
	cd $(LIBS_PATH) && $(MAKE)

clean:
	cd $(LIBS_PATH)src && rm ./*.o