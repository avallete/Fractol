/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 13:28:21 by avallete          #+#    #+#             */
/*   Updated: 2015/02/01 13:33:17 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	draw_to_img(t_mle *env, unsigned int place, int *rgb)
{
	if (place < IMG_MAX)
	{
		if (rgb)
		{
			C_IA(env)[place] = rgb[2];
			C_IA(env)[place + 1] = rgb[1];
			C_IA(env)[place + 2] = rgb[0];
			C_IA(env)[place + 3] = rgb[3];
		}
	}
}
