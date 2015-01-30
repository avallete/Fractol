/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fougere.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 15:23:45 by avallete          #+#    #+#             */
/*   Updated: 2015/01/30 19:48:51 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	fill_rect(t_mle *env, int x, int y, int x2, int y2, int mode)
{
	int tmp;
	int inc;
	int	incy;

	tmp = x;
	x2 > x ? (inc = 1) : (inc = -1);
	y2 > y ? (incy = 1): (incy = -1);
	if (mode)
		RGB(C_FR(env)->rgb, 0, 255, 0);
	else
		RGB(C_FR(env)->rgb, 0, 0, 0);
	while (y != y2)
	{
		x = tmp;
		while (x != x2)
		{
			draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
			x += inc;
		}
		y += incy;
		draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
	}
}

void	recurse_sierpinski(t_mle *env, long double x, long double y, long double xs, long double ys, int it)
{
	if (it > 0)
	{
		fill_rect(env, (int)(x+xs/3), (int)(y + ys/3), (int)(x+2*xs/3), (int)(y+2*ys/3), 0);
		recurse_sierpinski(env, x, y, xs/3, ys/3, it - 1);
		recurse_sierpinski(env, x+xs/3, y, xs/3, ys/3, it - 1);
		recurse_sierpinski(env, x+2*xs/3, y, xs/3, ys/3, it - 1);
		recurse_sierpinski(env, x, y+ys/3, xs/3, ys/3, it - 1);
		recurse_sierpinski(env, x+2*xs/3, y+(ys/3), xs/3, ys/3, it - 1);
		recurse_sierpinski(env, x, y+2*ys/3, xs/3, ys/3, it - 1);
		recurse_sierpinski(env, x+xs/3, y+2*ys/3, xs/3, ys/3, it - 1);
		recurse_sierpinski(env, x+2*xs/3, y+2*ys/3, xs/3, ys/3, it - 1);
	}
	else
		fill_rect(env, (int)x, (int)y, (int)x + xs, (int)y + ys, 1);
}

void	create_sierpinski(t_mle *env)
{
//	fill_rect(env, 5, 5, 10, 10, 1);
	recurse_sierpinski(env, 0, 0, WINDOW_W, WINDOW_H, 2);
}

void	print_sierpinski(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_sierpinski(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}
