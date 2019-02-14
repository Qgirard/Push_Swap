# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 16:35:29 by qgirard           #+#    #+#              #
#    Updated: 2019/02/04 16:41:33 by qgirard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC1 = checker
EXEC2 = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH1 = checker/
SRC_PATH2 = push_swap/

re : fclean all

.PHONY : all clean fclean re
