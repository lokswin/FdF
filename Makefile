# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drafe <drafe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by drafe             #+#    #+#              #
#    Updated: 2019/08/31 21:12:56 by nshelly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NAME = fdf

HEADERS = fdf.h

LIBS = -L./Libft/ -lft\
	-lmlx -framework OpenGL -framework AppKit

OBJS = $(SRCS:.c=.o)

SRCS = src/main.c\
	src/fdf_draw.c\
	src/fdf_ui.c\
	src/fdf_reform.c\
	src/fdf_new_win.c\
	src/fdf_colors.c\
	src/fdf_color_change.c\
	src/fdf_keys.c\
	src/fdf_points.c

all: $(NAME)

$(NAME):$(OBJS) | lib
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I . -o $@ -c $<

lib:
	make -C./Libft

clean:
	make clean -C./Libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C./Libft
	rm -f $(NAME)

re: fclean all

