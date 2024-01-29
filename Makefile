NAME = so_long
CCFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -fsanitize=address -g

LIBFT = ./lib/libft
LIBMLX = ./lib/MLX42

HDRS = -I./include -I $(LIBFT)/include -I $(LIBMLX)/include $(shell pkg-config --cflags glfw3)
LIBS = $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl $(shell pkg-config --libs glfw3) -pthread -lm -fsanitize=address
SRCS = src/error.c src/game.c src/graphic.c src/main.c src/read_map.c \
	src/render_map.c src/validate_map.c src/validate_path.c
OBJS = $(SRCS:%.c=%.o)

all: libft libmlx $(NAME)

libft: 
	@make -C $(LIBFT)

%.o : %.c
    @$(CC) $(CCFLAGS) -o $@ -c $< $(HDRS) && printf "Compiling: $(notdir $<)\n"

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o : %.c
	@$(CC) $(CCFLAGS) -o $@ -c $< $(HDRS) && printf "Compiling so_long: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HDRS) -o $(NAME) -framework Cocoa -framework OpenGL -framework IOKit

clean:
	@echo "Cleaning object files and build directories..."
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@rm -rf $(LIBFT)/build
	@make -C $(LIBFT) clean

fclean: clean
	@echo "Removing executable..."
	@rm -rf $(NAME)
	@make clean -C $(LIBMLX)
	@make fclean -C $(LIBFT)

re: fclean all
	@echo "Rebuilding everything..."

.PHONY: all clean fclean re libft libmlx

check_leaks: $(NAME)
	./$(NAME) & sleep 1 && leaks $! && wait