/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:15:38 by avallete          #+#    #+#             */
/*   Updated: 2015/01/31 16:33:37 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
# include <libft.h>
# include <X.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# define WINDOW_W 500
# define WINDOW_H 500
# define IMG_MAX ((WINDOW_W * WINDOW_H) * 4)
# define PLACE_IMG(x, y) ((y * (WINDOW_W * 4)) + x * 4)
# define RGB(c, r, g, b) (c[0] = r, c[1] = g, c[2] = b)
# define CENTERX (WINDOW_W / 2)
# define CENTERY (WINDOW_H / 2)
# define MOD(z)	(((z->r * z->r) + (z->i * z->i)))
# define MANDELBROT_X1 -2.1
# define MANDELBROT_X2 0.6
# define MANDELBROT_Y1 -1.2
# define MANDELBROT_Y2 1.2
# define ZOOM_X(x1, x2) ((WINDOW_W / (x2 - x1)))
# define ZOOM_Y(y1, y2) ((WINDOW_H / (y2 - y1)))
# define C_IM(x)	((t_draw*)x->content)->simg->img
# define C_IA(x)	((t_draw*)x->content)->simg->imgdata
# define C_IL(x)	((t_draw*)x->content)->inf->line
# define C_IP(x)	((t_draw*)x->content)->inf->px
# define C_IC(x)	((t_draw*)x->content)->inf->c
# define C_IT(x)	((t_draw*)x->content)->inf->type
# define C_FR(x)	((t_draw*)x->content)->inf->fra
# define C_CO(x)	((t_draw*)x->content)->inf->col1
# define C_IF(x)	((t_draw*)x->content)->inf
# define ECHAP		0xFF1B
# define UP			0xFF52
# define DOWN		0xFF54
# define LEFT		0xFF51
# define RIGHT		0xFF53
# define PLUS		0xFFAB
# define MINS		0xFFAD
# define K_C		99
# define K_X		120
# define K_P		112

typedef struct		s_mle
{
	void			*mlx;
	void			*win;
	void			*content;
}					t_mle;

typedef struct		s_img
{
	void			*img;
	char			*imgdata;
}					t_img;

typedef struct		s_nc
{
	long double		r;
	long double		i;
}					t_nc;

typedef struct		s_rc
{
	int		x;
	int		y;
	int		xs;
	int		ys;
}					t_rc;

typedef	struct		s_fra
{
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	int				*rgb;
	unsigned int	it;
	unsigned int	x;
	unsigned int	y;
}					t_fra;

typedef	struct		s_inf
{
	int				*type;
	int				*zoom;
	int				*line;
	int				*px;
	int				*c;
	int				col1;
	long double		cr;
	long double		ci;
	t_fra			*fra;
}					t_inf;

typedef	struct		s_draw
{
	t_img			*simg;
	t_inf			*inf;
}					t_draw;

/*
** ----------
** Arguments checking functions
** ----------
*/

void	check_name(char *name, int *i);
void	print_fract(t_mle *env);

/*
** ----------
** Init stucture functions
** ----------
*/

void	init_simg(t_img *simg);
void	init_xymandel(t_fra *fra);
void	init_fra(t_fra *fra, int type);
void	init_inf(t_inf *inf, int *tab, t_fra *sfra, int *rgb);

/*
** ----------
** Window hook functions
** ----------
*/

int		expose_hook(t_mle *env);
int		key_hook(int keycode, t_mle *env);
int		mouse_hook(int button, int x, int y, t_mle *env);

/*
** ----------
** Keyboard key functions
** ----------
*/

void	key_echap(t_mle *env);
void	zoom(t_mle *env, int mode);
int		modify_prec(t_mle *env, int mode);
void	key_move(t_mle *env, int type, float mode);
void	modify_color(t_mle *env, int mode);

/*
** ----------
** Mouse keys functions
** ----------
*/
void	controled_zoom(t_mle *env, int x, int y, int mode);
int		modify_xy_fract(int x, int y, t_mle *env);
int		modify_col_fract(int x, int y, t_mle *env);


/*
** ----------
** Create && print fractales
** ----------
*/

/*
** Mandelbrot 
*/
void	print_mandelbrot(t_mle *env);
void	create_mandelbrot(t_mle *env);
unsigned int	it_mandel(t_nc z, t_nc c, t_mle *env);

/*
** Julia 
*/
void	print_julia(t_mle *env);
void	create_julia(t_mle *env);

/*
** Sierpinski
*/
void	print_sierpinski(t_mle *env);
void	create_sierpinski(t_mle *env);

/*
** Newton
*/
void	print_newton(t_mle *env);
void	create_newton(t_mle *env);
unsigned int it_newton(t_nc z, t_nc c, t_mle *env);

/*
** ----------
** Draw 
** ----------
*/

void	draw_to_img(t_mle *env, unsigned int place, int *rgb);
#endif
