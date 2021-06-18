
FILE = $(wildcard *.c) \
	   $(wildcard utils/*.c) \
	   $(wildcard render/*.c)

CC = gcc

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
	$(CC) $(FILE) $(MLX) $(LIBFT) -D OS=$(OS) $(KEY) 