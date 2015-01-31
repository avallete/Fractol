/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 10:12:47 by avallete          #+#    #+#             */
/*   Updated: 2015/01/31 18:30:53 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void	check_name(char *name, int *i)
{
	if (!(ft_strcmp("Mandelbrot", name)))
		*i = 1;
	else if (!(ft_strcmp("Julia", name)))
		*i = 2;
	else if (!(ft_strcmp("Lapin", name)))
		*i = 3;
	else if (!(ft_strcmp("Newton", name)))
		*i = 4;
	else
		*i = 0;
}

void	print_fract(t_mle *env)
{
	if (*C_IT(env) == 1)
		print_mandelbrot(env);
	else if (*C_IT(env) == 2)
		print_julia(env);
	else if (*C_IT(env) == 3)
		print_sierpinski(env);
	else if (*C_IT(env) == 4)
		print_newton(env);
}
