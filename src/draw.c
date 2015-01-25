/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 13:28:21 by avallete          #+#    #+#             */
/*   Updated: 2015/01/25 16:52:47 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	print_fract(t_mle *env)
{
	if (*C_IT(env) == 1)
		print_mandelbrot(env);
}

void	create_mandelbrot(t_mle *env)
{
	int it = 20;
	int y;
	int x;
	t_nc c;
	t_nc z;
	long double tmp;
	int	cm;
	int rgb[3];

	y = 0;
	tmp = 0;
	while (y < WINDOW_H)
	{
		x = 0;
		while (x < WINDOW_W)
		{
			c.r = x / ZOOM_X(MANDELBROT_X1, MANDELBROT_X2) + MANDELBROT_X1;
			c.i = y / ZOOM_Y(MANDELBROT_Y1, MANDELBROT_Y2) + MANDELBROT_Y1;
			z.r = 0;
			z.i = 0;
			cm = 0;
			while (z.r*z.r + z.i*z.i < 4 && cm < it)
			{
				tmp = z.r;
				z.r = z.r*z.r - z.i*z.i + c.r;
				z.i = 2 * z.i * tmp + c.i;
				cm++;
			}
			if (cm == it)
			{
				RGB(rgb, 255, 0, 0);
				draw_to_img(env, PLACE_IMG(x, y), rgb);
			}
			else
			{
				RGB(rgb, 0, 0, cm*255/it);
				draw_to_img(env, PLACE_IMG(x, y), rgb);
			}
			x++;
		}
		y++;
	}
}

void	print_mandelbrot(t_mle *env)
{
	C_IM(env) ? mlx_destroy_image(env->mlx, C_IM(env)), (C_IM(env) = NULL) : \
		(C_IM(env) = mlx_new_image(env->mlx, WINDOW_W, WINDOW_H));
	if (C_IM(env) && \
			((C_IA(env) = mlx_get_data_addr(C_IM(env), C_IP(env), C_IL(env), C_IC(env)))))
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
