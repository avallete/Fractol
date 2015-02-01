/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 10:04:40 by avallete          #+#    #+#             */
/*   Updated: 2015/02/01 09:58:28 by avallete         ###   ########.fr       */
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
	fra->x1 = -2.0;
	fra->x2 = 2.0;
	fra->y1 = -2.0;
	fra->y2 = 2.0;
	fra->it = 5;
	fra->x = 0;
	fra->y = 0;
}

void	init_fra(t_fra *fra, int type)
{
	if (type == 1 || type == 2 || type == 3 || type == 4)
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
	inf->col1 = 0;
	inf->cr	= 0.285;
	inf->ci = 0.01;
}

