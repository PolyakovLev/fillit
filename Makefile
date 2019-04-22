# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daharwoo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/25 17:37:01 by ramory-l          #+#    #+#              #
#    Updated: 2018/12/19 15:43:31 by daharwoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

OBJ = $(patsubst %.c, %.o, $(wildcard srcs/*.c)) main.o

FLAGS = -Wall -Wextra -Werror

HEADER = includes

HEADERDIR = libft/includes

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME) -I $(HEADERDIR) -L libft/ -lft

%.o: %.c $(HEADER)
	gcc $(FLAGS) -I $(HEADERDIR) -I $(HEADER) -c $< -o $@ -g

$(LIB):
	make -C libft/

clean:
	rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all