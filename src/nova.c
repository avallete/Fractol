/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nova.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 13:58:09 by avallete          #+#    #+#             */
/*   Updated: 2015/02/03 14:20:58 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	it_nova(t_nc z, t_nc c, t_mle *env)
{
	unsigned int cm;
	long double tmp;

	cm = 0;
	while (cm < C_FR(env)->it)
	{
		tmp = z.r;
		z.r = z.r - c.r*(z.i - 1)/(z.r*z.i - 1) + c.r;
		z.i = z.i - c.i*(tmp - 1)/(z.i*tmp - 1) - c.i;
		cm++;
	}
	if (z.r > 0.0)
		RGB(C_FR(env)->rgb, 230, 126, 34+C_CO(env), 255);
	else if (z.r <= 0.3 && z.i > 0.0)
		RGB(C_FR(env)->rgb, 192, 57, 43+C_CO(env), 255);
	else
		RGB(C_FR(env)->rgb, 241, 196 , 15+C_CO(env), 255);
}

void	create_nova(t_mle *env)
{
	int y;
	int x;
	t_nc z;
	t_nc c;

	y = C_FR(env)->y;
	while (y < WINDOW_H)
	{
		x = C_FR(env)->x;
		while (x < WINDOW_W)
		{
			z.r = x / ZOOM_X(C_FR(env)->x1, C_FR(env)->x2) + C_FR(env)->x1;
			z.i = y / ZOOM_Y(C_FR(env)->y1, C_FR(env)->y2) + C_FR(env)->y1;
			c.r = 2.0 + C_IF(env)->cr;
			c.i = 2.0 + C_IF(env)->ci;
			it_nova(z, c, env);
			draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
			x++;
		}
		y++;
	}
}

void	print_nova(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_nova(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}
