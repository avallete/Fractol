/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 10:04:40 by avallete          #+#    #+#             */
/*   Updated: 2015/02/03 15:27:50 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	init_base_colors(t_mle *env)
{
	if (*C_IT(env) == 1)
		CO_MAND(env);
	if (*C_IT(env) == 2)
		CO_JULI(env);
	if (*C_IT(env) == 3)
		CO_LAPI(env);
	if (*C_IT(env) == 6)
		CO_BURN(env);
	if (*C_IT(env) == 7)
		CO_CROI(env);
	if (*C_IT(env) == 8)
		CO_FUZZ(env);
	if (*C_IT(env) == 9)
		CO_TETR(env);
	if (*C_IT(env) == 10)
		CO_TETR(env);
}

void	init_colors(t_mle *env, unsigned int cm)
{
	init_base_colors(env);
	if (cm != C_FR(env)->it)
		CO_DEGR(env);
}

void	init_simg(t_img *simg)
{
	simg->img = NULL;
	simg->imgdata = NULL;
}

void	init_xymandel(t_fra *fra)
{
	fra->x1 = -2.0;
	fra->x2 = 2.0;
	fra->y1 = -2.0;
	fra->y2 = 2.0;
	fra->it = 10;
	fra->x = 0;
	fra->y = 0;
}


void	init_xysierpinski(t_fra *fra)
{
	fra->x1 = 0;
	fra->x2 = WINDOW_W;
	fra->y1 = 0;
	fra->y2 = WINDOW_H;
	fra->it = 2;
	fra->x = 0;
	fra->y = 0;
}

void	init_fra(t_fra *fra, int type)
{
	if (type)
		init_xymandel(fra);
}

void	init_ci(t_inf *inf, int type)
{
	if (type == 2)
	{
		inf->cr	= 0.285;
		inf->ci = 0.01;
	}
	else
	{
		inf->cr	= 0.0;
		inf->ci = 0.0;
	}
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
	inf->col1 = 0;
}

