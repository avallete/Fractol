/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:15:38 by avallete          #+#    #+#             */
/*   Updated: 2015/02/08 12:12:55 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
# include <math.h>
# include "libft.h"
# include <X11/X.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define WINDOW_W 500
# define WINDOW_H 500
# define IMG_MAX ((WINDOW_W * WINDOW_H) * 4)
# define PLACE_IMG(x, y) ((y * (WINDOW_W * 4)) + x * 4)
# define RGB(c, r, g, b, a) (c[0] = r, c[1] = g, c[2] = b, c[3] = a)
# define CENTERX (WINDOW_W / 2)
# define CENTERY (WINDOW_H / 2)
# define MOD(z)	(((z->r * z->r) + (z->i * z->i)))
# define MANDELBROT_X1 -2.0
# define MANDELBROT_X2 2.0
# define MANDELBROT_Y1 -2.0
# define MANDELBROT_Y2 2.0
# define ZOOM_X(x1, x2) ((WINDOW_W / (x2 - x1)))
# define ZOOM_Y(y1, y2) ((WINDOW_H / (y2 - y1)))
# define CO_BURN(x)	RGB(C_FR(x)->rgb, 41 + C_CO(x), 128, 185, 255)
# define CO_MAND(x)	RGB(C_FR(x)->rgb, 26 + C_CO(x), 188, 156, 255)
# define CO_LAPI(x)	RGB(C_FR(x)->rgb, 102, 204 - C_CO(x), 153, 255)
# define CO_JULI(x)	RGB(C_FR(x)->rgb, 142, 68, 173 - C_CO(x), 255)
# define CO_CROI(x)	RGB(C_FR(x)->rgb, 228, 241, 254 - C_CO(x), 255)
# define CO_FUZZ(x)	RGB(C_FR(x)->rgb, 248 - C_CO(x), 148, 78, 255)
# define CO_TETR(x)	RGB(C_FR(x)->rgb, 65, 131, 215 - C_CO(x), 255)
# define CO_GLYN(x)	RGB(C_FR(x)->rgb, 46, 204 -  C_CO(x), 113, 255)
# define CO_MOIR(x)	RGB(C_FR(x)->rgb, 232 -  C_CO(x), 76, 109, 255)
# define CO_JUBI(x)	RGB(C_FR(x)->rgb, 52, 152, 219 - C_CO(x), 255)
# define CO_SOLE(x)	RGB(C_FR(x)->rgb, 241 -  C_CO(x), 196, 15, 255)
# define DEGRR(x)	(((cm*C_FR(x)->rgb[0])/C_FR(env)->it))
# define DEGRG(x)	(((cm*C_FR(x)->rgb[1])/C_FR(env)->it))
# define DEGRB(x)	(((cm*C_FR(x)->rgb[2])/C_FR(env)->it))
# define CO_DEGR(x) RGB(C_FR(x)->rgb, DEGRR(x), DEGRG(x), DEGRB(x), 255)
# define C_IM(x)	((t_draw*)x->content)->simg.img
# define C_IA(x)	((t_draw*)x->content)->simg.imgdata
# define C_IL(x)	((t_draw*)x->content)->inf.line
# define C_IP(x)	((t_draw*)x->content)->inf.px
# define C_IC(x)	((t_draw*)x->content)->inf.c
# define C_IT(x)	((t_draw*)x->content)->inf.type
# define C_FR(x)	((t_draw*)x->content)->inf.fra
# define C_CO(x)	((t_draw*)x->content)->inf.col1
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
# define K_R		114
# define CLK_R		Button3MotionMask

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
	t_img			simg;
	t_inf			inf;
}					t_draw;

/*
** ----------
** Arguments checking functions
** ----------
*/
void				check_name(char *name, int *i);
void				print_fract(t_mle *env);

/*
** ----------
** Init stucture functions
** ----------
*/

void				init_simg(t_img *simg);
void				init_xymandel(t_fra *fra);
void				init_fra(t_fra *fra, int type);
void				init_inf(t_inf *inf, int *tab, t_fra *sfra, int *rgb);
void				init_colors(t_mle *env, unsigned int cm);
void				init_base_colors(t_mle *env);
void				init_ci(t_inf *inf, int type);

/*
** ----------
** Window hook functions
** ----------
*/

int					expose_hook(t_mle *env);
int					key_hook(int keycode, t_mle *env);
int					mouse_hook(int button, int x, int y, t_mle *env);

/*
** ----------
** Keyboard key functions
** ----------
*/

void				key_echap(t_mle *env);
void				zoom(t_mle *env, int mode);
int					modify_prec(t_mle *env, int mode);
void				key_move(t_mle *env, int type, float mode);
void				modify_color(t_mle *env, int mode);
void				key_reset(t_mle *env);

/*
** ----------
** Mouse keys functions
** ----------
*/
void				controled_zoom(t_mle *env, int x, int y, int mode);
int					modify_xy_fract(int x, int y, t_mle *env);
int					modify_col_fract(int x, int y, t_mle *env);

/*
** ----------
** Create && print fractales
** ----------
*/

/*
** Mandelbrot
*/
void				print_mandelbrot(t_mle *env);
unsigned int		it_mandel(t_nc z, t_nc c, t_mle *env);

/*
** Julia
*/
void				print_julia(t_mle *env);

/*
** Newton
*/
void				print_newton(t_mle *env);

/*
** Lapin
*/
void				print_lapin(t_mle *env);

/*
** Burning Ship
*/
void				print_burningship(t_mle *env);

/*
** Croix
*/
void				print_croix(t_mle *env);

/*
** Fuzzy
*/
void				print_fuzzy(t_mle *env);

/*
** Tetration
*/
void				print_tetration(t_mle *env);

/*
** Glynn
*/
void				print_glynn(t_mle *env);

/*
** Moire
*/
void				print_moire(t_mle *env);

/*
** JuliaBis
*/
void				print_juliabis(t_mle *env);

/*
** Soleil
*/
void				print_soleil(t_mle *env);

/*
** ----------
** Draw
** ----------
*/
void				draw_to_img(t_mle *env, unsigned int place, int *rgb);
void				draw_dx(t_nc *start, int *dir, t_mle *env);
void				draw_dy(t_nc *start, int *dir, t_mle *env);
void				connect_pts(t_mle *env, t_nc start, t_nc end);

/*
** ----------
** Operation in complexes numbers
** ----------
*/

long double			module_nc(t_nc nb);
long double			argument_nc(t_nc nb);
long double			result_nc(t_nc nb);
long double			add_nc(t_nc nb1, t_nc nb2);
long double			mul_nc(t_nc nb1, t_nc nb2);
#endif
