# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ykarimi <ykarimi@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2024/05/29 10:38:04 by ykarimi       #+#    #+#                  #
#    Updated: 2024/05/29 15:27:27 by ykarimi       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := cc
CFLAGS := -Wall -Wextra -Werror
MLX42FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
INCLUDES := -I./include -I./lib/libft/include -I./lib/get_next_line/include -I./lib/MLX42/include/MLX42
BUILD_DIR := build
SRC_DIR := src
LIBFT := lib/libft/libft.a
GNL := lib/get_next_line/get_next_line.a
MLX42 := lib/MLX42/MLX42.a
SRCS = $(shell find src -name '*.c')
OBJS := $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(GNL) $(MLX42) $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT) $(GNL) $(MLX42) $(MLX42FLAGS)
	
$(LIBFT):
	make -C lib/libft

$(GNL):
	make -C lib/get_next_line

$(MLX42):
	make -C lib/MLX42

clean:
	make -C lib/libft clean
	make -C lib/get_next_line clean
	rm -rf $(BUILD_DIR)

fclean: clean
	make -C lib/libft fclean
	make -C lib/get_next_line fclean
	make -C lib/MLX42 fclean
	rm -f $(NAME).a
	

re: fclean all

.PHONY: all clean fclean re