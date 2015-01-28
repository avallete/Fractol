/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 10:17:38 by avallete          #+#    #+#             */
/*   Updated: 2015/01/28 16:20:28 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	zoom(t_mle *env, int mode)
{
	long double ex;
	long double ey;

	mode > 0 ? ((ex = (C_FR(env)->x2 - C_FR(env)->x1) / 5)) :\
	((ex = (C_FR(env)->x1 - C_FR(env)->x2) / 5));
	mode > 0 ? ((ey = (C_FR(env)->y2 - C_FR(env)->y1) / 5)) :\
	((ey = (C_FR(env)->y1 - C_FR(env)->y2) / 5));
	C_FR(env)->x1 += ex;
	C_FR(env)->x2 -= ex;
	C_FR(env)->y1 += ey;
	C_FR(env)->y2 -= ey;
}

int		modify_prec(t_mle *env, int mode)
{
	C_FR(env)->it += mode;
	return (0);
}

void	key_echap(t_mle *env)
{
	env = env;
	exit(0);
}

void	key_move(t_mle *env, int type, float mode)
{
	if (type == 1)
		C_FR(env)->x1 += mode, C_FR(env)->x2 += mode;
	if (type == 2)
		C_FR(env)->y1 += mode, C_FR(env)->y2 += mode;
}

void	modify_color(t_mle *env, int mode)
{
	C_CO(env) += mode;
	ft_putnbr(C_CO(env));
}
