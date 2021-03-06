/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 13:29:45 by avallete          #+#    #+#             */
/*   Updated: 2015/02/08 11:43:37 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

static unsigned int		it_tetration(t_nc z, t_mle *env)
{
	unsigned int	cm;
	t_nc			tmp;

	cm = 0;
	while (cm < C_FR(env)->it && hypot(z.r, z.i) < 100000)
	{
		tmp.r = exp(-0.5 * M_PI * z.i);
		tmp.i = M_PI * z.r / 2;
		z.r = (tmp.r * cos(tmp.i)) + C_IF(env).cr;
		z.i = (tmp.r * sin(tmp.i)) - C_IF(env).ci;
		cm++;
	}
	return (cm);
}

static void				create_tetration(t_mle *env)
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
			cm = it_tetration(z, env);
			init_colors(env, cm);
			draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
			x++;
		}
		y++;
	}
}

void					print_tetration(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_tetration(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}
