/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 13:28:21 by avallete          #+#    #+#             */
/*   Updated: 2015/01/26 19:50:50 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	print_fract(t_mle *env)
{
	if (*C_IT(env) == 1)
		print_mandelbrot(env);
}

unsigned int	it_mandel(t_nc z, t_nc c, t_mle *env)
{
	unsigned int cm;
	long double	tmp;

	cm = 0;
	tmp = 0;
	while (((z.r*z.r + z.i*z.i) < 4) && (cm < C_FR(env)->it))
	{
		tmp = z.r;
		z.r = z.r*z.r - z.i*z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		cm++;
	}
	return (cm);
}

void	create_mandelbrot(t_mle *env)
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
			c.r = x / ZOOM_X(C_FR(env)->x1, C_FR(env)->x2) + C_FR(env)->x1;
			c.i = y / ZOOM_Y(C_FR(env)->y1, C_FR(env)->y2) + C_FR(env)->y1;
			z.r = 0;
			z.i = 0;
			cm = it_mandel(z, c, env);
			if (cm == C_FR(env)->it)
			{
				RGB(C_FR(env)->rgb, 5, 5, 5);
				draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
			}
			else
			{
				if (cm < 50)
					RGB(C_FR(env)->rgb, 0, cm*255/C_FR(env)->it, 0);
				else if (cm > 50 && cm < 100)
					RGB(C_FR(env)->rgb, 0, cm*255/C_FR(env)->it, cm*255/C_FR(env)->it);
				else 
					RGB(C_FR(env)->rgb, cm*255/C_FR(env)->it, cm*255/C_FR(env)->it, cm*255/C_FR(env)->it);
				draw_to_img(env, PLACE_IMG(x, y), C_FR(env)->rgb);
			}
			x++;
		}
		y++;
	}
}

void	print_mandelbrot(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_mandelbrot(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}

void	draw_to_img(t_mle *env, unsigned int place, int *rgb)
{
	if (place < IMG_MAX)
	{
		if (rgb)
		{
			C_IA(env)[place] = rgb[2];
			C_IA(env)[place + 1] = rgb[1];
			C_IA(env)[place + 2] = rgb[0];
			C_IA(env)[place + 3] = 255;
		}
	}
}
