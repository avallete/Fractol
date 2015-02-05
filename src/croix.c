/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   croix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 11:53:42 by avallete          #+#    #+#             */
/*   Updated: 2015/02/05 12:33:43 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

unsigned int	it_croix(t_nc z, t_nc c, t_mle *env)
{
	unsigned int	cm;
	t_nc			tmp;

	cm = 0;
	while (cm < C_FR(env)->it && ((z.r > -0.5 && z.r < 1.5) || \
	(z.i > -0.25 && z.i < 1.0)))
	{
		if (z.r > C_FR(env)->x1 || z.r < C_FR(env)->x2)
		{
			tmp.r = z.r + z.i;
			z.i = -z.r + z.i + c.r;
			z.r = tmp.r;
			cm++;
		}
		else if (z.i > C_FR(env)->y1 || z.i < C_FR(env)->y2)
		{
			tmp.r = z.r - z.i;
			z.i = z.r + z.i - c.i;
			z.r = tmp.r;
			cm++;
		}
	}
	return (cm);
}

void			create_croix(t_mle *env)
{
	int				y;
	int				x;
	t_nc			c;
	t_nc			z;
	unsigned int	cm;

	y = C_FR(env)->y;
	while (y < WINDOW_H)
	{
		x = C_FR(env)->x;
		while (x < WINDOW_W)
		{
			z.r = x / ZOOM_X(C_FR(env)->x1, C_FR(env)->x2) + C_FR(env)->x1;
			z.i = y / ZOOM_Y(C_FR(env)->y1, C_FR(env)->y2) + C_FR(env)->y1;
			c.r = 1.0 + C_IF(env).cr;
			c.i = 2.0 - C_IF(env).ci;
			cm = it_croix(z, c, env);
			init_colors(env, cm);
			draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
			x++;
		}
		y++;
	}
}

void			print_croix(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_croix(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}
