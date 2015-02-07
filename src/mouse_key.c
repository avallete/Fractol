/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 11:04:28 by avallete          #+#    #+#             */
/*   Updated: 2015/02/07 16:15:26 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

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

int		modify_xy_fract(int x, int y, t_mle *env)
{
	static int	c = 0;
	long double x1;
	long double y1;

	c++;
	if (c == 5)
	{
		c = 0;
		x1 = x;
		y1 = y;
		x1 /= WINDOW_W;
		y1 /= WINDOW_H;
		while (x1 > 1)
			x1 /= 10;
		while (y1 > 1)
			y1 /= 10;
		while (x1 < -1)
			x1 *= 10;
		while (y1 < -1)
			y1 *= 10;
		C_IF(env).cr = x1;
		C_IF(env).ci = y1;
		expose_hook(env);
	}
	return (0);
}
