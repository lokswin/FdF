# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drafe <drafe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by drafe             #+#    #+#              #
#    Updated: 2019/08/11 17:05:22 by drafe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NAME = fdf

HEADERS = fdf.h

LIBS = -L./Libft/ -lft\
	-lmlx -framework OpenGL -framework AppKit

OBJS = $(SRCS:.c=.o)

SRCS = main.c\
	fdf_draw.c\
	fdf_ui.c\
	fdf_p_struct.c\
	fdf_reform.c\
	fdf_new_win.c\

all: $(NAME)

$(NAME):$(OBJS) | lib
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $<

lib:
	@make -C./Libft

clean:
	@make clean -C./Libft
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -C./Libft
	@rm -f $(NAME)

re: fclean all

