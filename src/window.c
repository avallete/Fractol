/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:19:28 by avallete          #+#    #+#             */
/*   Updated: 2015/02/05 15:16:31 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

int		mouse_hook(int button, int x, int y, t_mle *env)
{
	if (button == 4)
		controled_zoom(env, x, y, 1);
	if (button == 5)
		controled_zoom(env, x, y, -1);
	expose_hook(env);
	return (0);
}

int		key_hook(int keycode, t_mle *env)
{
	if (keycode == ECHAP)
		key_echap(env);
	if (keycode == UP || keycode == DOWN)
		keycode == UP ? key_move(env, 2, 0.01) : key_move(env, 2, -0.01);
	if (keycode == LEFT || keycode == RIGHT)
		keycode == LEFT ? key_move(env, 1, 0.01) : key_move(env, 1, -0.01);
	if (keycode == PLUS && C_FR(env)->it)
		modify_prec(env, 1);
	if (keycode == MINS && C_FR(env)->it > 1)
		modify_prec(env, -1);
	if (keycode == K_C || keycode == K_X)
		keycode == K_C ? modify_color(env, 2) : modify_color(env, -2);
	if (keycode == K_P || keycode == K_R)
		keycode == K_P ? C_CO(env) = 0 : key_reset(env);
//	mlx_destroy_window(env->mlx, C_IM(env));
//	(C_IM(env) = mlx_new_image(env->mlx, WINDOW_W, WINDOW_H));
	expose_hook(env);
	return (0);
}

int		expose_hook(t_mle *env)
{
	print_fract(env);
	return (0);
}
