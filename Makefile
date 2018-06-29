# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/28 10:11:15 by pierre            #+#    #+#              #
#    Updated: 2018/06/29 18:32:48 by pierre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DBG=-ggdb -fsanitize=address -fno-omit-frame-pointer -g3
DBG2=-ggdb  -fsanitize=address -fsanitize-memory-track-origins

CC = gcc
DIR= cryptopals/
LIB_PRINTF = ft_printf/libftprintf.a
LIB_PRINTF_PATH = ft_printf/
LIB_PRINTF_HEADER = ft_printf/inc
LIB_PRINTF_LINK = ftprintf
LIB = libft/libft.a
LIB_PATH = libft/
LIB_HEADER = libft/includes
LIB_LINK = ft
SRC_DIR = src/
INC_DIR = inc/
CFLAGS = -Wall -Werror -Wextra -I $(LIB_HEADER) -I $(LIB_PRINTF_HEADER) -I $(INC_DIR)
LIB_FLAGS = -L$(LIB_PRINTF_PATH) -l$(LIB_PRINTF_LINK) -L$(LIB_PATH) -l$(LIB_LINK)
			
$(LIB)	:
	make -C $(LIB_PATH)

$(LIB_PRINTF)	:
	make -C $(LIB_PRINTF_PATH)

%.c: $(LIB) $(LIB_PRINTF)
	$(CC) $(CFLAGS) $(DIR)$@ -o crypto $(LIB_FLAGS)

clean	:
	make -C $(LIB_PATH) fclean
	make -C $(LIB_PRINTF_PATH) fclean

re		: clean
