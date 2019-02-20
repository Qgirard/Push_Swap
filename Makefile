# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 16:35:29 by qgirard           #+#    #+#              #
#    Updated: 2019/02/20 17:53:44 by qgirard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC1 = checker
EXEC2 = push_swap

COMPILIB = make -C libftprintf
CLIB = make -C libftprintf clean
FCLIB = make -C libftprintf fclean
LIB = libftprintf/libftprintf.a

HEADER1 = checker.h
HEADER2 = push_swap.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC1 = checker/checker.c checker/checkermain.c checker/freecauses.c \
			checker/makepiles.c checker/rotate.c
SRC2 = push_swap/makelists.c push_swap/moves.c push_swap/needfree.c \
			push_swap/push_swap.c push_swap/pushmain.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ1) $(OBJ2)
	$(COMPILIB) && $(CC) $(EXEC1) $(CFLAGS) $(SRC1) $(LIB)
	&& $(CC) $(EXEC2) $(CFLAGS) $(SRC2) $(LIB)

clean :
	rm -rf $(OBJ1)
	rm -rf $(OBJ2)
	$(CLIB)

fclean : clean
	rm -rf $(EXEC1)
	rm -rf $(EXEC2)
	$(FCLIB)

re : fclean all

.PHONY : all clean fclean re
