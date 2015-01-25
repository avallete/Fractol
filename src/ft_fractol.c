/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:10:15 by avallete          #+#    #+#             */
/*   Updated: 2015/01/25 16:52:46 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	init_simg(t_img *simg)
{
	simg->img = NULL;
	simg->imgdata = NULL;
}

void	init_inf(t_inf *inf, int *tab)
{
	inf->line = &tab[0];
	inf->c = &tab[1];
	inf->px = &tab[2];
	inf->type = &tab[3];
	inf->zoom = &tab[4];
}

void	check_name(char *name, int *i)
{
	if (!(ft_strcmp("Mandelbrot", name)))
		*i = 1;
	else if (!(ft_strcmp("Julia", name)))
		*i = 2;
	else
		*i = 0;
}

int		ft_fractol(t_mle *env, char *name)
{
	check_name(name, C_IT(env));
	if (!(*C_IT(env)))
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
		t_inf	inf;
		int		tab[5];

		tab[0] = WINDOW_W;
		tab[1] = 1;
		tab[2] = (4 * sizeof(char));
		init_inf(&inf, tab);
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
	return (0);
}
