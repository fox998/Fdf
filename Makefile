# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afokin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/08 18:04:18 by afokin            #+#    #+#              #
#    Updated: 2017/12/08 18:04:20 by afokin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c readmap.c

OBG = $(SRC:.c=.o)

FLAG = -Wextra -Werror -Wall

NAME = fdf

HED = fdf.h

LIBFT_DIR = ./libft/

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(OBG) $(HED)
	make -C $(LIBFT_DIR)
	gcc $(FLAG) $(OBG) -o $(NAME) -L$(HED)

%.o: %.c
	gcc $(FLAG) -o $@ -c $<

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBG)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
