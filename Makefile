# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 17:13:40 by enoviell          #+#    #+#              #
#    Updated: 2023/02/28 19:12:34 by enoviell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINILIBX_PATH	=	./mlx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	so_long.c\
					draw.c\
					init.c\
					map.c\
					map_validate.c\
					player.c\
					game.c\
					exit.c\
					animation.c\
					moves.c\
					win.c\
					draw_wall.c\


HEADER			=	./so_long.h

OBJECTS			= 	$(SOURCES_FILES:.c=.o)

NAME			=	so_long

CC				=	gcc

RM				=	rm -f

MLX				=	./libmlx.dylib

CFLAGS			=	-Wall -Wextra -Werror

%.o: %.c
	$(CC) ${CFLAGS} -Imlx -c $< -o $@

all:			$(NAME)

$(NAME):	$(OBJECTS) $(LIBFT)
				$(CC) $(OBJECTS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MINILIBX):
				make -C $(MINILIBX_PATH)

$(LIBFT):
				make -C $(LIBFT_PATH)

clean:
				${RM} ${OBJECTS}
				make clean -C ${LIBFT_PATH}
				make clean -C ${MINILIBX_PATH}

fclean:			clean
					rm -f $(NAME)
					rm -f ${LIBFT}
					rm -f ${MINILIBX}

re:				fclean all

.PHONY:			all clean re