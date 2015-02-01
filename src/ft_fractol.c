/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:10:15 by avallete          #+#    #+#             */
/*   Updated: 2015/02/01 13:32:42 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	ft_putsterr(char *str)
{
	write(2, str, ft_strlen(str));
}

void	print_usage(void)
{
	ft_putsterr("Usage: ./Fractol [fractal name]\n");
	ft_putsterr("Corrects names : Mandelbrot, Julia\n");
}

int		ft_fractol(t_mle *env, char *name)
{
	check_name(name, C_IT(env));
	if (!(*C_IT(env)))
	{
		print_usage();
		return (-1);
	}
	else
	{
		init_fra(C_FR(env), *C_IT(env));
		C_IM(env) ? mlx_destroy_image(env->mlx, C_IM(env)), (C_IM(env) = NULL) : \
		(C_IM(env) = mlx_new_image(env->mlx, WINDOW_W, WINDOW_H));
	if (C_IM(env) && \
			((C_IA(env) = mlx_get_data_addr(C_IM(env), C_IP(env), C_IL(env), C_IC(env)))))
		mlx_expose_hook(env->win, expose_hook, env);
		mlx_key_hook(env->win, key_hook, env);
		mlx_mouse_hook(env->win, mouse_hook, env);
		mlx_hook(env->win, MotionNotify, Button3MotionMask, modify_xy_fract, env);
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
		t_inf	inf;
		t_fra	fra;
		int		rgb[4];
		int		tab[5];

		tab[0] = WINDOW_W;
		tab[1] = 1;
		tab[2] = (4 * sizeof(char));
		init_inf(&inf, tab, &fra, rgb);
		init_simg(&simg);
		sdraw.simg = &simg;
		sdraw.inf = &inf;
		env.content = &sdraw;
		if ((env.mlx = mlx_init()))
		{
			if ((env.win = mlx_new_window(env.mlx, WINDOW_W, WINDOW_H, "ft_fractol")))
				ft_fractol(&env, argv[1]);
		}
	}
	else
		print_usage();
	return (0);
}
