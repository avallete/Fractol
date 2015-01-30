/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 10:38:12 by avallete          #+#    #+#             */
/*   Updated: 2015/01/30 15:57:20 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	create_julia(t_mle *env)
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
			c.r = C_IF(env)->cr;
			c.i = C_IF(env)->ci;
			cm = it_mandel(z, c, env);
			if (cm == C_FR(env)->it)
				RGB(C_FR(env)->rgb, 0, 0, 0);
			else if (C_CO(env))
				RGB(C_FR(env)->rgb, ((cm*255/C_FR(env)->it*C_CO(env)*4) / 150), ((cm*255/C_FR(env)->it*C_CO(env)*2) / 255), ((cm*255/C_FR(env)->it*C_CO(env)*3) / 200));
			else
				RGB(C_FR(env)->rgb, 0, ((cm*255/C_FR(env)->it)), 0);
				draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
			x++;
		}
		y++;
	}
}

void	print_julia(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_julia(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}
