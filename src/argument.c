/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 10:12:47 by avallete          #+#    #+#             */
/*   Updated: 2015/02/03 13:26:37 by avallete         ###   ########.fr       */
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
	else if (!(ft_strcmp("Sierpinski", name)))
		*i = 5;
	else if (!(ft_strcmp("Burning Ship", name)))
		*i = 6;
	else if (!(ft_strcmp("Croix", name)))
		*i = 7;
	else if (!(ft_strcmp("Fuzzy", name)))
		*i = 8;
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
		print_lapin(env);
	else if (*C_IT(env) == 4)
		print_newton(env);
	else if (*C_IT(env) == 5)
		print_sierpinski(env);
	else if (*C_IT(env) == 6)
		print_burningship(env);
	else if (*C_IT(env) == 7)
		print_croix(env);
	else if (*C_IT(env) == 8)
		print_fuzzy(env);
}
