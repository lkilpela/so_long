NAME = so_long
CCFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
LIBMLX = ./MLX42

HDRS = -I. -I $(LIBMLX)/include $(shell pkg-config --cflags glfw3)
LIBS = $(LIBMLX)/build/libmlx42.a -ldl $(shell pkg-config --libs glfw3) -pthread -lm
SRCS = srcs/main.c \
	srcs/map.c \
	srcs/init.c \
	srcs/player.c \
	srcs/utils.c \
	srcs/render.c \
	srcs/validate_map.c \
	get_next_line/get_next_line_utils.c \
	get_next_line/get_next_line.c
OBJS = $(SRCS:%.c=%.o)

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.c : so_long.h error.h

%.o : %.c
	@$(CC) $(CCFLAGS) -o $@ -c $< $(HDRS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HDRS) -o $(NAME) -framework Cocoa -framework OpenGL -framework IOKit

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@rm -rf $(LIBMLX)/src/*.o

fclean: clean
	@rm -rf $(NAME)
	make clean -C $(LIBMLX)

re: fclean all

.PHONY: all clean fclean re libmlx