/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_keybis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 11:41:07 by avallete          #+#    #+#             */
/*   Updated: 2015/02/05 12:41:00 by avallete         ###   ########.fr       */
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

void	key_reset(t_mle *env)
{
	init_ci(&C_IF(env), *C_IT(env));
	init_fra(C_FR(env), *C_IT(env));
}
