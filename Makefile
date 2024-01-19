CCFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast 
NAME = so_long
LIBMLX = ./MLX42

HDRS = -I. -I ./include -I $(LIBMLX)/include $(shell pkg-config --cflags glfw3)
LIBS = $(LIBMLX)/build/libmlx42.a -ldl $(shell pkg-config --libs glfw3) -pthread -lm
SRCS = main.c srcs/map.c
OBJS = $(SRCS:%.c=%.o)

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o : %.c
	@$(CC) $(CCFLAGS) -o $@ -c $< $(HDRS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HDRS) -o $(NAME) -framework Cocoa -framework OpenGL -framework IOKit

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)
	make clean -C $(LIBMLX)

re: fclean all

.PHONY: all clean fclean re libmlx