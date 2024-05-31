# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ykarimi <ykarimi@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2024/05/29 10:38:04 by ykarimi       #+#    #+#                  #
#    Updated: 2024/05/31 16:04:25 by ykarimi       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := cc
CFLAGS := -Wall -Wextra -Werror
MLX42FLAGS = -lglfw
INCLUDES := -I./include -I./lib/libft/include -I./lib/get_next_line/include -I./lib/MLX42/include/MLX42
BUILD_DIR := build
SRC_DIR := src
INC_DIR := include
LIBFT := lib/libft/libft.a
GNL := lib/get_next_line/get_next_line.a
MLX42 := lib/MLX42/MLX42.a
SRCS = $(wildcard $(SRC_DIR)/*.c)
#OBJS = $(SRCS:.c=.o)
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
	#$(MAKE) -C lib/MLX42 fclean
	rm -f $(NAME).a
	

re: fclean all

.PHONY: all clean fclean re