/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 10:17:38 by avallete          #+#    #+#             */
/*   Updated: 2015/02/05 11:41:50 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

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
	if (C_CO(env) + mode >= 40 || C_CO(env) + mode <= -40)
		C_CO(env) += mode;
	else
		C_CO(env) += mode * 2;
}
