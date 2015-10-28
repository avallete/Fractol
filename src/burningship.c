/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 11:34:52 by avallete          #+#    #+#             */
/*   Updated: 2015/02/07 16:22:55 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

static unsigned int	it_burningship(t_nc z, t_nc c, t_mle *env)
{
	unsigned int	cm;
	t_nc			tmp;

	cm = 0;
	while (cm < C_FR(env)->it && (z.r * z.r + z.i * z.i) < 10)
	{
		tmp.r = (z.r * z.r) - (z.i * z.i) - c.r;
		tmp.i = 2 * fabsl(z.r * z.i) - c.i;
		z.r = tmp.r;
		z.i = tmp.i;
		cm++;
	}
	return (cm);
}

static void			create_burningship(t_mle *env)
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
			c.r = 1.625 - C_IF(env).cr;
			c.i = 0.035 + C_IF(env).ci;
			cm = it_burningship(z, c, env);
			init_colors(env, cm);
			draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
			x++;
		}
		y++;
	}
}

void				print_burningship(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_burningship(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}
