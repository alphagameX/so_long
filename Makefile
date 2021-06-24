
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


ifeq ($(OS), Darwin)
mlx_all:
	@cd mlx_osx && make
	@echo "mlx ready"
mlx_clean:
	@cd mlx_osx && make clean
	@echo "mlx clean"
else
mlx_all:
	@echo "mlx ready"
mlx_clean:
	@echo "mlx clean"
endif

all:
	@cd libft && make re
	@make mlx_all
	$(CC) $(FILE) $(MLX) $(LIBFT) -D OS=$(OS) $(KEY) -o $(NAME) -D STEP=4 -D DIE_DELAY=1

clean:
	@make mlx_clean
	@cd libft && make clean

fclean: clean
	@cd libft && make fclean
	@rm -rf $(NAME)

re: fclean
	@cd libft && make re
	@make all


bonus: re

# .PHONY: all
.DEFAULT_GOAL:= all

