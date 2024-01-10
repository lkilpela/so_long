CCFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
NAME = so_long
LIBMLX = ./MLX42

HDRS = -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS = $(shell find ./src -iname "*.c")
OBJS = $(SRCS:%.c=%.o)

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o : %.c
	@$(CC) $(CCFLAGS) -o $@ -c $< $(HEADERS) && print "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx