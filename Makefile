# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ykarimi <ykarimi@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2024/05/29 10:38:04 by ykarimi       #+#    #+#                  #
#    Updated: 2024/06/19 11:55:40 by ykarimi       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := cc
CFLAGS := -Wall -Werror -Wextra -g
MLX42FLAGS = -lglfw
LIBFT_INCLUDES := -I./lib/libft/include
GNL_INCLUDES := -I./lib/get_next_line/include
MLX_INCLUDES := -I./lib/MLX42/include/MLX42
SO_LONG_INCLUDES := -I./include
INCLUDES = $(LIBFT_INCLUDES) $(GNL_INCLUDES) $(MLX_INCLUDES) $(SO_LONG_INCLUDES) 
BUILD_DIR := bin
SRC_DIR := src
INC_DIR := include
LIBFT := lib/libft/libft.a
GNL := lib/get_next_line/get_next_line.a
MLX42 := lib/MLX42/MLX42.a
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
MLX42 = lib/MLX42/build/libmlx42.a

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(GNL) $(MLX42) $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) $(MLX42FLAGS) $(OBJS) $(LIBFT) $(GNL) $(MLX42) $(LIBFT) -o $(NAME)
	
$(LIBFT):
	$(MAKE) -C lib/libft

$(GNL): $(LIBFT)
	$(MAKE) -C lib/get_next_line

# $(MLX42):
# 	cd lib/MLX42 && cmake -B build
# 	# gcc main.c ... libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
# 	# make -C lib/MLX42
# 	# cc main.c -Wall -Wextra lib/MLX42/build/libmlx42.a -I[mlx42_folder]/include -ldl -lglfw -pthread -lm
$(MLX42):
	cd lib/MLX42 && cmake -B build && cmake --build build -j4

clean:
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/get_next_line clean
	rm -rf $(BUILD_DIR)

fclean: clean
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/get_next_line fclean
	rm -f $(NAME).a
	

re: fclean all

test:
	valgrind --leak-check=full --show-leak-kinds=all

@printf "OBJS		: $(OBJS)\n"
	
.PHONY: $(LIBFT) all clean fclean re
