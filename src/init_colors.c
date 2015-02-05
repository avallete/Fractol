/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 11:43:05 by avallete          #+#    #+#             */
/*   Updated: 2015/02/05 11:43:39 by avallete         ###   ########.fr       */
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
		CO_GLYN(env);
	if (*C_IT(env) == 11)
		CO_MOIR(env);
	if (*C_IT(env) == 12)
		CO_JUBI(env);
	if (*C_IT(env) == 13)
		CO_SOLE(env);
}

void	init_colors(t_mle *env, unsigned int cm)
{
	init_base_colors(env);
	if (cm != C_FR(env)->it)
		CO_DEGR(env);
}
