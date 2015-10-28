/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 13:28:21 by avallete          #+#    #+#             */
/*   Updated: 2015/02/02 15:16:16 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	connect_pts(t_mle *env, t_nc start, t_nc end)
{
	int dir[4];

	dir[0] = fabsl(end.r - start.r);
	dir[1] = fabsl(end.i - start.i);
	dir[2] = (dir[0] > 0) ? 1 : -1;
	dir[3] = (dir[1] > 0) ? 1 : -1;
	draw_to_img(env, PLACE_IMG(start.r, start.i), C_FR(env)->rgb);
	if (dir[0] > dir[1])
		draw_dx(&start, dir, env);
	else
		draw_dy(&start, dir, env);
}

void	draw_dy(t_nc *start, int *dir, t_mle *env)
{
	int err;
	int i;

	i = 1;
	err = dir[1] / 2;
	while (i <= dir[1])
	{
		start->i += dir[3];
		err += dir[0];
		if (err >= dir[1])
		{
			err -= dir[1];
			start->r += dir[2];
		}
		i++;
		draw_to_img(env, PLACE_IMG(start->r, start->i), C_FR(env)->rgb);
	}
}

void	draw_dx(t_nc *start, int *dir, t_mle *env)
{
	int err;
	int i;

	i = 1;
	err = dir[0] / 2;
	while (i <= dir[0])
	{
		start->r += dir[2];
		err += dir[1];
		if (err >= dir[0])
		{
			err -= dir[0];
			start->i += dir[3];
		}
		i++;
		draw_to_img(env, PLACE_IMG(start->r, start->i), C_FR(env)->rgb);
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
			C_IA(env)[place + 3] = rgb[3];
		}
	}
}
