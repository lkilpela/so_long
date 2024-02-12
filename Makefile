NAME = so_long
CCFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g

LIBFT = ./lib/libft
LIBMLX = ./lib/MLX42

HDRS = -I./include -I $(LIBFT)/include -I $(LIBMLX)/include
LIBS = $(LIBFT)/build/libft.a $(LIBMLX)/build/libmlx42.a $(shell pkg-config --libs glfw3) -ldl -pthread -lm
SRCS = src/error.c src/game.c src/graphic.c src/main.c src/read_map.c \
	src/render_map.c src/validate_map.c src/validate_path.c
OBJS = $(SRCS:%.c=%.o)

all: libft libmlx $(NAME)

libft: 
	@make -C $(LIBFT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o : %.c
	@echo "\033[32m[so_long] Compiling: $< into $@\033[0m"
	@$(CC) $(CCFLAGS) -o $@ -c $< $(HDRS)

$(NAME): $(OBJS)
	@echo "\033[1;32m[so_long] Linking static library libft.a and libmlx42.a\033[0m"
	@$(CC) $(OBJS) $(LIBS) $(HDRS) -o $(NAME) -framework Cocoa -framework OpenGL -framework IOKit
	@echo "[so_long] Built target so_long"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean
	@echo "[so_long] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/build
	@echo "[so_long] Everything deleted."

re: fclean all
	@echo "[so_long] Everything rebuilt."

.PHONY: all clean fclean re libft libmlx