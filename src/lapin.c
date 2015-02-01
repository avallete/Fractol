/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lapin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 10:00:43 by avallete          #+#    #+#             */
/*   Updated: 2015/02/01 13:40:14 by avallete         ###   ########.fr       */
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
			if (cm == C_FR(env)->it)
				RGB(C_FR(env)->rgb, 5, 5, 5, 255);
			else if (C_CO(env))
				RGB(C_FR(env)->rgb, cm*255/C_FR(env)->it*C_CO(env)*C_IF(env)->cr, cm*255/C_FR(env)->it*C_CO(env), cm*255/C_CO(env)*C_IF(env)->ci, 255);
			else
				RGB(C_FR(env)->rgb, 0, ((cm*255/C_FR(env)->it))*C_IF(env)->cr, 0*C_IF(env)->ci, 255);
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
