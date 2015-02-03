/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couloir.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 13:58:09 by avallete          #+#    #+#             */
/*   Updated: 2015/02/03 15:57:25 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

unsigned int	it_couloir(t_nc z, t_nc c, t_mle *env)
{
	unsigned int cm;
	long double tmp;

	cm = 0;
	while (cm < C_FR(env)->it && (fabs(c.r) > 0.05))
	{
		z.r = z.r - (0.33334*z.r) + (0.33334/(z.r*z.r));
		c.r = z.r - c.i;
		c.i = z.r;
		cm++;
	}
	return (cm);
}

void	create_couloir(t_mle *env)
{
	int y;
	int x;
	t_nc z;
	t_nc c;
	unsigned int cm;

	y = C_FR(env)->y;
	while (y < WINDOW_H)
	{
		x = C_FR(env)->x;
		while (x < WINDOW_W)
		{
			z.r = x / ZOOM_X(C_FR(env)->x1, C_FR(env)->x2) + C_FR(env)->x1;
			z.i = y / ZOOM_Y(C_FR(env)->y1, C_FR(env)->y2) + C_FR(env)->y1;
			c.r = 0.06;
			c.i = 0;
			cm = it_couloir(z, c, env);
			init_colors(env, cm);
			draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
			x++;
		}
		y++;
	}
}

void	print_couloir(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_couloir(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}
