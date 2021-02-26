
.PHONY: all clean fclean re
NAME = fractol
UNAME := $(shell uname -s)
	ifeq ($(UNAME),Linux)
		MLX_DIR = ./minilibx_linux/
		LIBS = -lmlx -L$(MLX_DIR) -lm -lXext -lX11
		KEY = linux_controls.c
	endif
	ifeq ($(UNAME),Darwin)
		MLX_DIR = ./minilibx_macos/
		LIBS = -lmlx -lm -L$(MLX_DIR) -framework OpenGL -framework AppKit
		KEY = mac_controls.c
	endif
HEADER = fractol.h
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror -O3 -pthread
SOURCES  = main.c initialize.c draw.c fractal.c operations.c ft_strcmp.c ft_putstr.c threads.c $(KEY)
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = -I$(HEADER_DIR) -I$(MLX_DIR)
MLX = $(MLX_DIR)libmlx.a
HEADER_DIR = .

all: $(NAME)

$(NAME): $(MLX) $(OBJECTS)
	$(COMPILER) $(FLAGS) $(OBJECTS) $(INCLUDES) $(LIBS) -o $(NAME)

%.o: %.c $(HEADER)
	$(COMPILER) $(FLAGS) -o $@ -c $(INCLUDES) $<

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX)

re: fclean all
