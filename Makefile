# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daalexan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 16:17:48 by daalexan          #+#    #+#              #
#    Updated: 2018/08/16 11:06:29 by daalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

HEADER = ./include/libft/
FILL_HEADER = ./include/

SRC = src

CFLAGS = -Wall -Werror -Wextra

CC = gcc

LIB_FILES = ./include/libft/
FILLER_FILES =  src/main.c \
				src/perefer_func.c \
				src/lists.c
				
OBJ = $(FILLER_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB_FILES)libft.a
	$(CC) -o $(NAME) $(OBJ) $(LIB_FILES)*.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER) -I $(FILL_HEADER)

$(LIB_FILES)libft.a:
	make -C $(LIB_FILES)
clean:
	make clean -C $(LIB_FILES)
	rm -f $(OBJ)
fclean: clean
	make fclean -C $(LIB_FILES)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
