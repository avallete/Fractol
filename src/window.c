/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:19:28 by avallete          #+#    #+#             */
/*   Updated: 2015/01/25 15:32:28 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

int		key_hook(int keycode, t_mle *env)
{
	if (keycode == 65307)
		key_echap(env);
	return (0);
}

int		expose_hook(t_mle *env)
{
	print_fract(env);
	return (0);
}
