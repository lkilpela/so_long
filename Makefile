NAME = so_long
CCFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g

LIBFT = ./lib/libft
LIBMLX = ./lib/MLX42

HDRS = -I./include -I $(LIBFT)/include -I $(LIBMLX)/include $(shell pkg-config --cflags glfw3)
LIBS = $(LIBFT)/build/libft.a $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm $(shell pkg-config --libs glfw3)
SRCS = src/error.c src/game.c src/graphic.c src/main.c src/read_map.c \
	src/render_map.c src/validate_map.c src/validate_path.c
OBJS = $(SRCS:%.c=%.o)

all: libft libmlx $(NAME)

libft: 
	@make -C $(LIBFT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o : %.c
	@$(CC) $(CCFLAGS) -o $@ -c $< $(HDRS)
	@echo "\033[32m[so_long] Compiling so_long: $(notdir $<)\033[0m"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HDRS) -o $(NAME) -framework Cocoa -framework OpenGL -framework IOKit

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean
	@echo "\033[32m[so_long] Object files cleaned.\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/build
	@echo "\033[32m[so_long] Everything deleted.\033[0m"

re: fclean all
	@echo "\033[32m[so_long] Everything rebuilt.\033[0m"

.PHONY: all clean fclean re libft libmlx