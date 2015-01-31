/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 10:37:53 by avallete          #+#    #+#             */
/*   Updated: 2015/01/31 17:58:05 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

long double		module_nc(t_nc nb)
{
	long double module;
	long double	x;

	x = (nb.r * nb.r) + (nb.i * nb.i);
	module = sqrt(x);
	return (module);
}

long double		argument_nc(t_nc nb)
{
	long double arccos;

	arccos = acos(nb.r / (module_nc(nb)));
	return (arccos);
}

long double		result_nc(t_nc nb)
{
	return (nb.r + nb.i);
}

long double		add_nc(t_nc nb1, t_nc nb2)
{
	return ((nb1.r + nb1.i) + (nb2.r + nb2.i));
}

long double		sous_nc(t_nc nb1, t_nc nb2)
{
	return ((nb1.r - nb1.i) + (nb2.r - nb2.i));
}

long double		mul_nc(t_nc nb1, t_nc nb2)
{
	return ((nb1.r + nb1.i)*(nb2.r + nb2.i));
}

unsigned int	it_newton(t_nc z, t_nc c, t_mle *env)
{
	unsigned int cm;
	long double	tmp;

	cm = 0;
	tmp = 0;
	while (((z.r*z.r + z.i*z.i)< 10) && (cm < C_FR(env)->it))
	{
		tmp = z.r;
		z.r = (z.r*z.r - z.i*z.i) - c.r;
		z.i = 2*abs(tmp*z.i) - c.i;
		cm++;
	}
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
	C_FR(env)->x1 = 1.755;
	C_FR(env)->y1 = 0.03;
	while (y < WINDOW_H)
	{
		x = C_FR(env)->x;
		while (x < WINDOW_W)
		{
			c.r = x / ZOOM_X(C_FR(env)->x1, C_FR(env)->x2) + C_FR(env)->x1;
			c.i = y / ZOOM_Y(C_FR(env)->y1, C_FR(env)->y2) + C_FR(env)->y1;
			z.r = 0;
			z.i = 0;
			cm = it_newton(z, c, env);
			if (cm == C_FR(env)->it)
				RGB(C_FR(env)->rgb, 5, 5, 5);
			else if (C_CO(env))
				RGB(C_FR(env)->rgb, cm*255/C_FR(env)->it*C_CO(env)*C_IF(env)->cr, cm*255/C_FR(env)->it*C_CO(env), cm*255/C_CO(env)*C_IF(env)->ci);
			else
				RGB(C_FR(env)->rgb, 0, ((cm*255/C_FR(env)->it))*C_IF(env)->cr, 0*C_IF(env)->ci);
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
