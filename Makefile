LIBMLX:=-L /usr/X11/lib -lmlx -lXext -lX11
CFLAGS=-Wall -Wextra -Werror

all:
	make -C libft/
	gcc $(CFLAGS) src/*.c -I includes/ -I libft/includes/ -L libft -lftprintf $(LIBMLX) -I /opt/X11/include/X11  -o Fractol

easy:
	make -C libft/
	gcc src/*.c -I includes/ -I libft/includes/ -L libft -lftprintf $(LIBMLX) -I /opt/X11/include/X11  -o Fractol
