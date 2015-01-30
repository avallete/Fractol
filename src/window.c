/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:19:28 by avallete          #+#    #+#             */
/*   Updated: 2015/01/30 19:48:58 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

int		mouse_hook(int button, int x, int y, t_mle *env)
{
	ft_putendl("Mouse button:");
	ft_putnbr(button);
	ft_putchar('\n');
	ft_putnbr(x);
	ft_putchar(':');
	ft_putnbr(y);
	ft_putchar('\n');
	if (button == 4)
		controled_zoom(env, x, y, 1);
	if (button == 5)
		controled_zoom(env, x, y, -1);
	expose_hook(env);
	return (0);
}
int		key_hook(int keycode, t_mle *env)
{
	ft_putendl("keyboard button:");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == ECHAP)
		key_echap(env);
	if (keycode == UP)
		key_move(env, 2, 0.01);
	if (keycode == DOWN)
		key_move(env, 2, -0.01);
	if (keycode == LEFT)
		key_move(env, 1, 0.01);
	if (keycode == RIGHT)
		key_move(env, 1, -0.01);
	if (keycode == PLUS)
		modify_prec(env, 10);
	if (keycode == MINS && C_FR(env)->it > 20)
		modify_prec(env, -10);
	if (keycode == K_C)
		modify_color(env, 2);
	if (keycode == K_X)
		modify_color(env, -2);
	if (keycode == K_P)
		C_CO(env) = 0;
	mlx_destroy_image(env->mlx, C_IM(env));
	(C_IM(env) = mlx_new_image(env->mlx, WINDOW_W, WINDOW_H));
	expose_hook(env);
	return (0);
}

int		expose_hook(t_mle *env)
{
	print_fract(env);
	return (0);
}
