/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:10:15 by avallete          #+#    #+#             */
/*   Updated: 2015/01/23 16:54:02 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	init_simg(t_img *simg)
{
	simg->img = NULL;
	simg->imgdata = NULL;
}

char	check_name(char *name)
{
	if (!(ft_strcmp("Mandelbrot", name)))
		return (1);
	else if (!(ft_strcmp("Julia", name)))
		return (2);
	else
		return (0);
}

int		ft_fractol(t_mle *env, char *name)
{
	char type;

	type = check_name(name);
	if ((!(type)))
		return (-1);
	else
	{
		mlx_expose_hook(env->win, expose_hook, env);
		mlx_key_hook(env->win, key_hook, env);
		mlx_loop(env->mlx);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		t_mle	env;
		t_img	simg;
		t_draw	sdraw;

		init_simg(&simg);
		sdraw.simg = &simg;
		env.content = &sdraw;
		if ((env.mlx = mlx_init()))
		{
			if ((env.win = mlx_new_window(env.mlx, WINDOW_W, WINDOW_H, "ft_fractol")))
				ft_fractol(&env, argv[1]);
		}
	}
	return (0);
}
