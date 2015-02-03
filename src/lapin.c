/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lapin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 10:00:43 by avallete          #+#    #+#             */
/*   Updated: 2015/02/03 15:22:56 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

unsigned int	it_lapin(t_nc z, t_nc c, t_mle *env)
{
	unsigned int cm;
	long double	tmp;

	cm = 0;
	tmp = 0;
	while ((module_nc(z)) < 8 && (cm < C_FR(env)->it))
	{
		tmp = (z.r * z.r) - (z.i * z.i);
		z.i = 2 * z.i * z.r + c.i;
		z.r = tmp + c.r;
		cm++;
	}
	return (cm);
}

void	create_lapin(t_mle *env)
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
			c.r = -0.122565;
			c.i = -0.744864;
			cm = it_lapin(z, c, env);
			init_colors(env, cm);
			draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
			x++;
		}
		y++;
	}
}

void	print_lapin(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_lapin(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}
