SRC_PATH=./src/
SRC_NAME=argument.c\
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
OBJ_PATH =./obj/
OBJ_NAME:=$(SRC_NAME:.c=.o)
INC_PATH=./includes/ /opt/X11/include/X11
INC_NAME=libft.h\
		ft_printf.h\
		X.h\
		ft_fractol.h
SRC:=$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ:=$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INCF:=$(addprefix $(INC_PATH), $(INC_NAME))
INC:=$(addprefix -I, $(INC_PATH))
LIBMLX=-L/usr/lib64/X11 -lX11 -lXext -L/usr/lib64/ -lmlx
LIBFT=-L libft -lftprintf
CFLAGS= -g
CC=-gcc
NAME=Fractol
RED=\033[0;31m
LBLUE=\033[1;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
NC=\033[0m

all: $(NAME)

$(NAME):$(OBJ)
	@make -s -C libft
	@echo "${RED}Compile $(NAME) with $(CFLAGS)${NC}";
	@gcc $(CLFAGS) $(OBJ) $(INC) -lm $(LIBMLX) $(LIBFT) -o $(NAME)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@echo "${ORANGE}Create bynary $@ with $<${NC}";
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@echo "${CYAN}Delete OBJ files${NC}"
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "${CYAN}Delete $(NAME) file${NC}"
	@rm -rf $(NAME)

re: fclean all clean

.PHONY: all clean fclean re
