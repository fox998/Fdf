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

SRC = main.c readmap.c get_map.c draw_line.c get_arr_int.c get_center.c \
 print_map.c mtr_rot.c  get_ax.c  mtr_init.c   get_color.c

OBG = $(SRC:.c=.o)

FLAG = -Wextra -Werror -Wall

NAME = fdf

HED = ./

LIBFT = libft/libft.a

LIBFT_DIR = ./libft/

.PHONY : all clean fclean re

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(LIBFT_DIR):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_DIR) $(OBG)
	@gcc -lmlx -framework OpenGL -framework AppKit $(FLAG) -I$(HED) $(OBG) libft/libft.a -o $(NAME)

%.o: %.c
	@gcc $(FLAG) -I$(HED) -o $@ -c $<

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBG)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all
