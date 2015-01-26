/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:19:28 by avallete          #+#    #+#             */
/*   Updated: 2015/01/26 19:48:55 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	zoom(t_mle *env, int mode)
{
	long double ex;
	long double ey;

	mode > 0 ? ((ex = (C_FR(env)->x2 - C_FR(env)->x1) / 5)) :\
	((ex = (C_FR(env)->x1 - C_FR(env)->x2) / 5));
	mode > 0 ? ((ey = (C_FR(env)->y2 - C_FR(env)->y1) / 5)) :\
	((ey = (C_FR(env)->y1 - C_FR(env)->y2) / 5));
	C_FR(env)->x1 += ex;
	C_FR(env)->x2 -= ex;
	C_FR(env)->y1 += ey;
	C_FR(env)->y2 -= ey;
}

void	controled_zoom(t_mle *env, int x, int y, int mode)
{
	long double	centerx;
	long double	centery;
	long double	xo;
	long double	yo;

	xo = x / ZOOM_X(C_FR(env)->x1, C_FR(env)->x2) + C_FR(env)->x1;
	yo = y / ZOOM_Y(C_FR(env)->y1, C_FR(env)->y2) + C_FR(env)->y1;
	centerx = (C_FR(env)->x1 + C_FR(env)->x2) / 2;
	centery = (C_FR(env)->y1 + C_FR(env)->y2) / 2;
	xo -= centerx;
	yo -= centery;
	C_FR(env)->x1 = C_FR(env)->x1 + xo;
	C_FR(env)->x2 = C_FR(env)->x2 + xo;
	C_FR(env)->y1 = C_FR(env)->y1 + yo;
	C_FR(env)->y2 = C_FR(env)->y2 + yo;
	zoom(env, mode);
}

int		mouse_hook(int button, int x, int y, t_mle *env)
{
	if (button == 4)
		controled_zoom(env, x, y, 1);
	if (button == 5)
		controled_zoom(env, x, y, -1);
	expose_hook(env);
	return (0);
}

int		modify_prec(t_mle *env, int mode)
{
	C_FR(env)->it += mode;
	return (0);
}

int		key_hook(int keycode, t_mle *env)
{
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == ECHAP)
		key_echap(env);
	if (keycode == UP)
		zoom(env, 1);
	if (keycode == DOWN)
		zoom(env, -1);
	if (keycode == PLUS)
		modify_prec(env, 10);
	if (keycode == MINS && C_FR(env)->it > 20)
		modify_prec(env, -10);
	mlx_destroy_image(env->mlx, C_IM(env));
	(C_IM(env) = mlx_new_image(env->mlx, WINDOW_W, WINDOW_H));
	expose_hook(env);
	return (0);
}

int		expose_hook(t_mle *env)
{
	print_fract(env);
	return (0);
}
