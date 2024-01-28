NAME = so_long
CCFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

LIBFT = ./lib/libft
LIBMLX = ./lib/MLX42

HDRS = -I./include -I $(LIBFT)/include -I $(LIBMLX)/include $(shell pkg-config --cflags glfw3)
LIBS = $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl $(shell pkg-config --libs glfw3) -pthread -lm
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:%.c=%.o)

all: libft libmlx $(NAME)

libft: 
	@make -C $(LIBFT)

%.o : %.c
    @$(CC) $(CCFLAGS) -o $@ -c $< $(HDRS) && printf "Compiling: $(notdir $<)\n"

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o : %.c
	@$(CC) $(CCFLAGS) -o $@ -c $< $(HDRS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HDRS) -o $(NAME) -framework Cocoa -framework OpenGL -framework IOKit

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@rm -rf $(LIBMLX)/src/*.o
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	make clean -C $(LIBMLX)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re libft libmlx