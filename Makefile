# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ykarimi <ykarimi@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2024/05/29 10:38:04 by ykarimi       #+#    #+#                  #
#    Updated: 2024/08/19 11:46:14 by ykarimi       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := cc
CFLAGS := -Wall -Werror -Wextra
MLX42FLAGS = -lglfw
LIBFT_INCLUDES := -I./lib/libft/include
MLX_INCLUDES := -I./lib/MLX42/include/MLX42
SO_LONG_INCLUDES := -I./include
INCLUDES = $(LIBFT_INCLUDES) $(MLX_INCLUDES) $(SO_LONG_INCLUDES)
BUILD_DIR := bin
SRC_DIR := src
INC_DIR := include
LIBFT := lib/libft/libft.a
MLX42 = lib/MLX42/build/libmlx42.a
SRCS = src/error_handling.c src/game_init.c src/game_start_utils.c src/load_game.c \
		src/main.c src/map_validity.c src/move_functions.c src/parsing_utils.c \
		src/parsing.c src/populate_map.c src/so_long.c src/cleanup.c \
		src/path_checker.c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(MLX42) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(MLX42FLAGS) $(OBJS) $(LIBFT) $(MLX42) -o $(NAME)
	
$(LIBFT):
	$(MAKE) -C lib/libft

$(MLX42):
	cd lib/MLX42 && cmake -B build && cmake --build build -j4

clean:
	$(MAKE) -C lib/libft clean
	rm -rf $(BUILD_DIR)

fclean: clean
	$(MAKE) -C lib/libft fclean
	rm -f $(NAME)
	
re: fclean all

memcheck:
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re $(LIBFT) $(MLX42)
