
NAME=so_long

FILE = $(wildcard *.c) \
	   $(wildcard function/*.c) \
	   $(wildcard function/map/*.c) \
	   $(wildcard function/player/*.c) \
	   $(wildcard function/hud/*.c) \
	   $(wildcard function/init/*.c) \
	   $(wildcard function/parse/*.c) \
	   $(wildcard render/*.c) 

CC = gcc -Wall -Werror -Wextra

OS=$(shell uname)

ifeq ($(OS), Darwin)
	MLX= -L./mlx_osx -lmlx -framework OpenGL -framework AppKit
	OS=0
else
	MLX= -L./mlx_linux -lmlx -L/usr/lib -lXext -lX11 -I/usr/include -lm -lz  -O3 
	OS=1
endif

LIBFT = -L./libft -lft

all: 
	$(CC) $(FILE) $(MLX) $(LIBFT) -D OS=$(OS) $(KEY) -g -o $(NAME)

libft_clean:
	@cd libft && make clean

ifeq ($(OS), Darwin)
clean: libft_clean
	@cd mlx_osx && make clean
else
clean: libft_clean	
endif

fclean: clean
	rm -rf $(NAME)

re: fclean all

