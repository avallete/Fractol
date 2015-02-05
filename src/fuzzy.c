/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuzzy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 11:25:03 by avallete          #+#    #+#             */
/*   Updated: 2015/02/05 13:32:52 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

static unsigned int	it_fuzzy(t_nc z, t_mle *env)
{
	unsigned int	cm;
	t_nc			tmp;

	cm = 0;
	while (cm < C_FR(env)->it && hypot(z.r, z.i) < 1.1)
	{
		tmp.r = 1 - fabs(z.r - z.i);
		z.i = 1 - fabs(z.i - (1 - z.r));
		z.r = tmp.r;
		cm++;
	}
	return (cm);
}

static void			create_fuzzy(t_mle *env)
{
	int				y;
	int				x;
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
			cm = it_fuzzy(z, env);
			init_colors(env, cm);
			draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
			x++;
		}
		y++;
	}
}

void				print_fuzzy(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_fuzzy(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}
