/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:15:38 by avallete          #+#    #+#             */
/*   Updated: 2015/01/25 16:52:45 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
# include <libft.h>
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
# define MANDELBROT_X2 -0.6
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

typedef	struct		s_inf
{
	int				*type;
	int				*zoom;
	int				*line;
	int				*px;
	int				*c;
}					t_inf;

typedef	struct		s_draw
{
	t_img			*simg;
	t_inf			*inf;
}					t_draw;


void	draw_to_img(t_mle *env, unsigned int place, int *rgb);
void	print_mandelbrot(t_mle *env);
void	print_fract(t_mle *env);
int		key_hook(int keycode, t_mle *env);
int		expose_hook(t_mle *env);
void	key_echap(t_mle *env);
#endif
