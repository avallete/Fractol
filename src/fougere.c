/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fougere.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 15:23:45 by avallete          #+#    #+#             */
/*   Updated: 2015/02/01 13:34:08 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

unsigned int	it_sierpinski(int x, int y, t_mle *env)
{
	unsigned int cm;

	cm = 0;
	while ((x > 0 || y > 0) && (cm < C_FR(env)->it))
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (cm);
		x /= 3;
		y /= 3;
		cm++;
	}
	return (cm);
}

void	create_sierpinski(t_mle *env)
{
	int y;
	int x;
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
			cm = it_sierpinski(x, y, env);
			if (cm == C_FR(env)->it)
				RGB(C_FR(env)->rgb, 5, 5 + cm, 5, 255);
			else if (C_CO(env))
				RGB(C_FR(env)->rgb, cm*255/C_FR(env)->it*C_CO(env)*C_IF(env)->cr, cm*255/C_FR(env)->it*C_CO(env), cm*255/C_CO(env)*C_IF(env)->ci, cm*255/C_FR(env)->it);
			else
				RGB(C_FR(env)->rgb, 0, ((cm*255/C_FR(env)->it))*C_IF(env)->cr, 0*C_IF(env)->ci, 255);
			draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
			x++;
		}
		y++;
	}
}

void	print_sierpinski(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_sierpinski(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}
