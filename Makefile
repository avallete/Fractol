LIBMLX:=-L /usr/X11/lib -lmlx -lXext -lX11

all:
	make -C libft/
	gcc -Wall -Wextra -Werror src/*.c -I includes/ -I libft/includes/ -L libft -lftprintf $(LIBMLX) -I /opt/X11/include/X11  -o Fractol

easy:
	make -C libft/
	gcc -w src/*.c -I includes/ -I libft/includes/ -L libft -lftprintf $(LIBMLX) -o Fractol
