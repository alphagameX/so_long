
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
	FILE += uname/exit_osx.c
else
	MLX= -L./mlx_linux -lmlx -L/usr/lib -lXext -lX11 -I/usr/include -lm -lz  -O3 
	OS=1
	FILE += uname/exit_linux.c
endif

LIBFT = -L./libft -lft

libft_clean:
	@cd libft && make clean
libft_all:
	@cd libft && make all

ifeq ($(OS), Darwin)
clean: libft_clean
	@cd mlx_osx && make clean
mlx_all:
	@cd mlx_osx && make
	@echo "mlx ready"
mlx_clean:
	@cd mlx_osx && make clean
	@echo "mlx clean"
else
clean: libft_clean	
mlx_all:
	@echo "mlx ready"
mlx_clean:
	@echo "mlx clean"
endif

all: libft_all mlx_all
	$(CC) $(FILE) $(MLX) $(LIBFT) -D OS=$(OS) $(KEY) -o $(NAME) -D STEP=3

fclean: clean libft_clean mlx_clean
	rm -rf $(NAME)

re: fclean libft_all mlx_all all

bonus: re

.DEFAULT: all

