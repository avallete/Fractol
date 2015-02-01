/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calnc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 10:02:23 by avallete          #+#    #+#             */
/*   Updated: 2015/02/01 10:06:34 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

long double		module_nc(t_nc nb)
{
	long double	x;

	x = (nb.r * nb.r) + (nb.i * nb.i);
	return (x);
}

long double		argument_nc(t_nc nb)
{
	long double arccos;

	arccos = acos(nb.r / (module_nc(nb)));
	return (arccos);
}

long double		result_nc(t_nc nb)
{
	return (nb.r + nb.i);
}

long double		add_nc(t_nc nb1, t_nc nb2)
{
	return ((nb1.r + nb1.i) + (nb2.r + nb2.i));
}

long double		sous_nc(t_nc nb1, t_nc nb2)
{
	return ((nb1.r - nb1.i) + (nb2.r - nb2.i));
}

long double		mul_nc(t_nc nb1, t_nc nb2)
{
	return ((nb1.r + nb1.i)*(nb2.r + nb2.i));
}
