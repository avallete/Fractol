/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fibonacci.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 14:03:38 by avallete          #+#    #+#             */
/*   Updated: 2015/02/02 18:50:44 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

long double		get_fibonacci(unsigned int it)
{
	long double a;
	long double b;
	long double tmp;

	a = 1;
	b = 1;
	while (it > 0)
	{
		tmp = a + b;
		a = b;
		b = tmp;
		it--;
	}
	return (a);
}

void	it_fibonacci(t_nc z, t_mle *env)
{
	t_nc z1;
	t_nc z2;
	unsigned int cm;
	unsigned int i;

	cm = 1;
	i = 1;
	z1.r = 0;
	z1.i = 0;
	z2.r = 0;
	z2.i = 0;
	while (i < C_FR(env)->it)
	{
		if (i % 9 == 0)
		{
			z.r += get_fibonacci(cm - 1)*sin(i - 180);
			z.i += get_fibonacci(cm - 1)*cos(i - 180);
			cm++;
		}
		z1.r = z2.r;
		z1.i = z2.i;
		z2.r = z.r+get_fibonacci(cm)*sin(i);
		z2.i = z.i+get_fibonacci(cm)*cos(i);
		RGB(C_FR(env)->rgb, 0, 0, 255, 255);
		if (i != 1)
			connect_pts(env, z1, z2);
		i++;
	}
}

void	create_fibonacci(t_mle *env)
{
	int y;
	int x;
	t_nc z;

	y = C_FR(env)->y;
	while (y < WINDOW_H)
	{
		x = C_FR(env)->x;
		while (x < WINDOW_W)
		{
			z.r = x;
			z.i = y;
			it_fibonacci(z, env);
			x++;
		}
		y++;
	}
}

void	print_fibonacci(t_mle *env)
{
	if (C_IM(env) && (C_IA(env)))
	{
		create_fibonacci(env);
		mlx_put_image_to_window(env->mlx, env->win, C_IM(env), 0, 0);
	}
}
