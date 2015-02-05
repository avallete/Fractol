LIBMLX:=-L /usr/X11/lib -lmlx -lXext -lX11
SRCFRACTOL:=argument.c\
burningship.c\
calnc.c\
croix.c\
draw.c\
ft_fractol.c\
fuzzy.c\
glynn.c\
init.c\
init_colors.c\
julia.c\
juliabis.c\
keyboard_key.c\
keyboard_keybis.c\
lapin.c\
mandelbrot.c\
moire.c\
mouse_key.c\
newton.c\
soleil.c\
tetration.c\
window.c
CFLAGS=-Wall -Wextra -Werror

all:
	make -C libft/
	gcc $(CFLAGS) src/*.c -I includes/ -I libft/includes/ -L libft -lftprintf $(LIBMLX) -I /opt/X11/include/X11  -o Fractol

easy:
	make -C libft/
	gcc src/*.c -I includes/ -I libft/includes/ -L libft -lftprintf $(LIBMLX) -I /opt/X11/include/X11  -o Fractol
