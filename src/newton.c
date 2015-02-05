/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 10:37:53 by avallete          #+#    #+#             */
/*   Updated: 2015/02/05 13:27:43 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

static void	it_newton(t_nc z, t_mle *env)
{
	unsigned int	cm;
	long double		tmp;
	long double		zzr;
	long double		zzi;
	long double		d;

	cm = 0;
	while (cm < C_FR(env)->it)
	{
		tmp = z.r;
		zzr = z.r * z.r;
		zzi = z.i * z.i;
		d = 3.0 * ((zzr - zzi) * (zzr - zzi) + 4.0 * (zzr * zzi));
		if (d == 0.0)
			d = 0.000001;
		z.r = (2.0 / 3.0) * z.r + (zzr - zzi) / d + C_IF(env).cr;
		z.i = (2.0 / 3.0) * z.i - 2.0 * tmp * z.i / d + C_IF(env).ci;
		cm++;
	}
	if (z.r > 0.0)
		RGB(C_FR(env)->rgb, 230, 126, 34 + C_CO(env), 255);
	else if (z.r <= 0.3 && z.i > 0.0)
		RGB(C_FR(env)->rgb, 192, 57, 43 + C_CO(env), 255);
	else
		RGB(C_FR(env)->rgb, 241, 196, 15 + C_CO(env), 255);
}

static void	create_newton(t_mle *env)
{
	int		y;
	int		x;
	t_nc	z;

	y = C_FR(env)->y;
	while (y < WINDOW_H)
	{
		x = C_FR(env)->x;
		while (x < WINDOW_W)
		{
			z.r = x / ZOOM_X(C_FR(env)->x1, C_FR(env)->x2) + C_FR(env)->x1;
			z.i = y / ZOOM_Y(C_FR(env)->y1, C_FR(env)->y2) + C_FR(env)->y1;
			it_newton(z, env);
			draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
			x++;
		}
		y++;
	}
}

void		print_newton(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_newton(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}
