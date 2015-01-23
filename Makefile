LIBMLX:=-L /usr/X11/lib -lmlx -lXext -lX11
all:
	make -C libft/
	gcc -Wall -Wextra -Werror src/*.c -I includes/ -I libft/includes/ -L libft -lftprintf $(LIBMLX)