/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 10:32:42 by avallete          #+#    #+#             */
/*   Updated: 2015/02/05 13:24:06 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

unsigned int	it_mandel(t_nc z, t_nc c, t_mle *env)
{
	unsigned int	cm;
	long double		tmp;

	cm = 0;
	tmp = 0;
	while (((z.r * z.r + z.i * z.i) < 4) && (cm < C_FR(env)->it))
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		cm++;
	}
	return (cm);
}

static void		create_mandelbrot(t_mle *env)
{
	int				y;
	int				x;
	t_nc			c;
	t_nc			z;
	unsigned int	cm;

	y = C_FR(env)->y;
	while (y < WINDOW_H)
	{
		x = C_FR(env)->x;
		while (x < WINDOW_W)
		{
			c.r = x / ZOOM_X(C_FR(env)->x1, C_FR(env)->x2) + C_FR(env)->x1;
			c.i = y / ZOOM_Y(C_FR(env)->y1, C_FR(env)->y2) + C_FR(env)->y1;
			z.r = 0 + C_IF(env).cr;
			z.i = 0 + C_IF(env).ci;
			cm = it_mandel(z, c, env);
			init_colors(env, cm);
			draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
			x++;
		}
		y++;
	}
}

void			print_mandelbrot(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_mandelbrot(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}
