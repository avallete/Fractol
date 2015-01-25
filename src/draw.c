/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 13:28:21 by avallete          #+#    #+#             */
/*   Updated: 2015/01/25 15:51:23 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	print_fract(t_mle *env)
{
	if (*C_IT(env) == 1)
		print_mandelbrot(env);
}

void	print_mandelbrot(t_mle *env)
{
	int rgb[3];

	rgb[0] = 255;
	rgb[1] = 255;
	rgb[2] = 255;
	C_IM(env) ? mlx_destroy_image(env->mlx, C_IM(env)), (C_IM(env) = NULL) : \
		(C_IM(env) = mlx_new_image(env->mlx, WINDOW_W, WINDOW_H));
	if (C_IM(env) && \
			((C_IA(env) = mlx_get_data_addr(C_IM(env), C_IP(env), C_IL(env), C_IC(env)))))
	{
		draw_to_img(env, PLACE_IMG(CENTERX, CENTERY), rgb);
		draw_to_img(env, PLACE_IMG(251, 251), rgb);
		draw_to_img(env, PLACE_IMG(252, 252), rgb);
		draw_to_img(env, PLACE_IMG(253, 253), rgb);
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
