/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:10:15 by avallete          #+#    #+#             */
/*   Updated: 2015/02/08 12:03:03 by avallete         ###   ########.fr       */
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
	ft_putsterr("Corrects names : Mandelbrot, Julia, Newton, \"Burning Ship\"\
, Croix, Fuzzy, Tetration, Glynn, JuliaBis, Lapin, Soleil, Moire\n");
}

int		ft_fractol(t_mle *env, char *name)
{
	check_name(name, C_IT(env));
	if (!(*C_IT(env)))
		print_usage();
	else
	{
		init_ci(&C_IF(env), *C_IT(env));
		init_fra(C_FR(env), *C_IT(env));
		C_IM(env) ? mlx_destroy_window(env->mlx, C_IM(env)), (C_IM(env) = NULL) \
		: (C_IM(env) = mlx_new_image(env->mlx, WINDOW_W, WINDOW_H));
		if (C_IM(env) && ((C_IA(env) = mlx_get_data_addr(C_IM(env), \
											C_IP(env), C_IL(env), C_IC(env)))))
			mlx_expose_hook(env->win, expose_hook, env);
		mlx_mouse_hook(env->win, mouse_hook, env);
		mlx_hook(env->win, MotionNotify, CLK_R, modify_xy_fract, env);
		mlx_hook(env->win, KeyPress, KeyRelease, key_hook, env);
		mlx_loop(env->mlx);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_mle	env;
	t_draw	sdraw;
	t_fra	fra;
	int		rgb[4];
	int		tab[5];

	if (argc > 1)
	{
		tab[0] = WINDOW_W;
		tab[1] = 1;
		tab[2] = (4 * sizeof(char));
		init_inf(&sdraw.inf, tab, &fra, rgb);
		init_simg(&sdraw.simg);
		env.content = &sdraw;
		if ((env.mlx = mlx_init()))
		{
			if ((env.win = mlx_new_window(env.mlx, WINDOW_W, \
				WINDOW_H, "ft_fractol")))
				ft_fractol(&env, argv[1]);
		}
	}
	else
		print_usage();
	return (0);
}
