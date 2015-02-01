/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 10:37:53 by avallete          #+#    #+#             */
/*   Updated: 2015/02/01 15:01:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

long double		cube(t_nc z)
{
	return (((z.r + z.i) * (z.r + z.i) * (z.r + z.i)) - 1.0);
}

long double	it_newton(t_nc z, t_nc c, t_mle *env)
{
	unsigned int cm;
	long double	tmp;
	long double zzr;
	long double	zzi;
	long double	d;

	cm = 0;
	while (cm < C_FR(env)->it)
	{
		tmp = z.r;
		zzr = z.r*z.r;
		zzi = z.i*z.i;
		d = 3.0*((zzr - zzi)*(zzr - zzi) + 4.0*(zzr*zzi));
		if (d == 0.0)
			d = 0.000001;
		z.r = (2.0/3.0)*z.r + (zzr - zzi)/d;
		z.i = (2.0/3.0)*z.i + 2.0*tmp*z.i/d;
		cm++;
	}
	if (z.r > 0.0)
		RGB(C_FR(env)->rgb, 255, 0, 0, 255);
	else if (z.r <= 0.3 && z.i > 0.0)
		RGB(C_FR(env)->rgb, 0, 0, 255, 255);
	else
		RGB(C_FR(env)->rgb, 0, 255, 0, 255);
	return (cm);
}

void	create_newton(t_mle *env)
{
	int y;
	int x;
	t_nc c;
	t_nc z;
	unsigned int cm;

	y = C_FR(env)->y;
	while (y < WINDOW_H)
	{
		x = C_FR(env)->x;
		while (x < WINDOW_W)
		{
			z.r = x / ZOOM_X(C_FR(env)->x1, C_FR(env)->x2) + C_FR(env)->x1;
			z.i = y / ZOOM_Y(C_FR(env)->y1, C_FR(env)->y2) + C_FR(env)->y1;
			c.r = 0;
			c.i = 0;
			cm = it_newton(z, c, env);
			draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
			x++;
		}
		y++;
	}
}

void	print_newton(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_newton(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}
