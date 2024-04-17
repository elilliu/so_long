# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 18:18:08 by elilliu           #+#    #+#              #
#    Updated: 2024/03/28 16:55:44 by elilliu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX_DIR = mlx

MLX_PATH = mlx/libmlx.a

INCLUDE = so_long.h

SRC = clean_all.c data_init.c fill_window.c fill_window_utils.c fill_window_utils2.c \
		ft_free_tiles.c ft_itoa.c ft_putstr_fd.c main.c map_init.c \
		move_player.c move_zombies.c open_exit.c player_chests_init.c player_death.c \
		player_exit.c player_on_chest.c put_banner.c tiles_init_basic.c tiles_init_counter.c \
		tiles_init_exit.c tiles_init_player.c tiles_init_zombie.c tiles_init.c verif_map.c \
		verif_map_utils.c verif_map_utils2.c verif_map_utils3.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ_DIR = objects

OBJ = ${addprefix ${OBJ_DIR}/, ${SRC:.c=.o}}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

${OBJ_DIR}/%.o: %.c ${INCLUDE}
		mkdir -p ${OBJ_DIR} ${OBJ_DIR}/gnl
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
		${CC} ${CFLAGS} ${OBJ} -o $@ ${MLX_PATH} -L${MLX_DIR} -lX11 -lXext -lmlx

all: ${NAME}

clean:
		rm -rf ${OBJ} ${OBJ_DIR}

fclean: clean;
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re ${OBJ_DIR}
