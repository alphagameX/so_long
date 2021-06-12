
FILE = $(wildcard *.c) \
	   $(wildcard utils/*.c) \
	   $(wildcard render/*.c)

CC = gcc

MLX = -L./mlx -l mlx -L/usr/lib -lXext -lX11 -I/usr/include -lm -lz  -O3 
LIBFT = -L./libft -lft

all: 
	$(CC) $(FILE) $(MLX) $(LIBFT) -g