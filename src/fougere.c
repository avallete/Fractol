/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fougere.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 15:23:45 by avallete          #+#    #+#             */
/*   Updated: 2015/01/30 19:27:10 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	fill_rect(t_mle *env, int x, int y, int xs, int ys, int mode)
{
	int i;
	int e;

	if (mode)
		RGB(C_FR(env)->rgb, 0, 255, 0);
	else
		RGB(C_FR(env)->rgb, 0, 0, 255);
	e = 0;
	while (ys > e)
	{
		i = 0;
		while (xs > i)
		{
			draw_to_img(env, PLACE_IMG((i + x), (e + y)), C_FR(env)->rgb);
			i++;
		}
		e++;
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
	recurse_sierpinski(env, 5, 5, WINDOW_W - 10, WINDOW_H - 10, 3);
}

void	print_sierpinski(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_sierpinski(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}
