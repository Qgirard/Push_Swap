# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 16:35:29 by qgirard           #+#    #+#              #
#    Updated: 2019/03/29 12:58:32 by qgirard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC1 = checker
EXEC2 = push_swap

COMPILIB = make -C libft
CLIB = make -C libft clean
FCLIB = make -C libft fclean
LIB = libft/libft.a

MLX = -I /usr/local/include
MLX_FLAGS = -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

HEADER1 = p_checker/checker.h
HEADER2 = p_pushswap/push_swap.h

CC = gcc -o
CFLAGS = -Wall -Wextra -Werror

SRC1 = p_checker/checker.c p_checker/checkermain.c p_checker/freecauses.c \
			p_checker/makepiles.c p_checker/rotate.c p_checker/pile_is_sort.c \
			p_checker/visu.c
SRC2 = p_pushswap/makelists.c p_pushswap/moves.c p_pushswap/needfree.c \
			p_pushswap/push_swap.c p_pushswap/pushmain.c \
			p_pushswap/mediane.c p_pushswap/checksort.c \
			p_pushswap/printactions.c p_pushswap/tri2_3nbs.c p_pushswap/recup.c \
			p_pushswap/push_rotate.c p_pushswap/makerr.c \
			p_pushswap/tri_when_pile.c p_pushswap/tri_pile_b.c \
			p_pushswap/reduce_actions.c p_pushswap/reduce_rotate.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all : $(LIB) $(EXEC1) $(EXEC2)

$(LIB) :
	$(COMPILIB)

$(EXEC1) : $(OBJ1)
	$(CC) $(EXEC1) $(CFLAGS) $(SRC1) $(LIB) $(MLX) $(MLX_FLAGS)

$(EXEC2) : $(OBJ2)
	$(CC) $(EXEC2) $(CFLAGS) $(SRC2) $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) -c -I $(HEADER1) $< -o $@

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
