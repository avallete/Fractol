/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:10:15 by avallete          #+#    #+#             */
/*   Updated: 2015/01/26 19:11:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	init_simg(t_img *simg)
{
	simg->img = NULL;
	simg->imgdata = NULL;
}

void	init_xymandel(t_fra *fra)
{
	fra->x1 = -2.1;
	fra->x2 = 0.6;
	fra->y1 = -1.2;
	fra->y2 = 1.2;
	fra->it = 20;
	fra->x = 0;
	fra->y = 0;
}

void	init_fra(t_fra *fra, int type)
{
	if (type == 1)
		init_xymandel(fra);
}

void	init_inf(t_inf *inf, int *tab, t_fra *sfra, int *rgb)
{
	inf->line = &tab[0];
	inf->c = &tab[1];
	inf->px = &tab[2];
	inf->type = &tab[3];
	inf->zoom = &tab[4];
	inf->fra = sfra;
	inf->fra->rgb = rgb;
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
		init_fra(C_FR(env), *C_IT(env));
		C_IM(env) ? mlx_destroy_image(env->mlx, C_IM(env)), (C_IM(env) = NULL) : \
		(C_IM(env) = mlx_new_image(env->mlx, WINDOW_W, WINDOW_H));
	if (C_IM(env) && \
			((C_IA(env) = mlx_get_data_addr(C_IM(env), C_IP(env), C_IL(env), C_IC(env)))))
		mlx_expose_hook(env->win, expose_hook, env);
		mlx_key_hook(env->win, key_hook, env);
		mlx_mouse_hook(env->win, mouse_hook, env);
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
		int		rgb[3];
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
	return (0);
}
