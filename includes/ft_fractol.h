/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:15:38 by avallete          #+#    #+#             */
/*   Updated: 2015/01/23 16:56:46 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
# include <libft.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# define WINDOW_W 500
# define WINDOW_H 500
# define CENTERX (WINDOW_W / 2)
# define CENTERY (WINDOW_H / 2)

typedef struct		s_mle
{
	void			*mlx;
	void			*win;
	void			*content;
}					t_mle;

typedef struct		s_img
{
	void			*img;
	char			*imgdata;
}					t_img;

typedef	struct		s_draw
{
	t_img			*simg;
}					t_draw;

int		key_hook(int keycode, t_mle *env);
int		expose_hook(t_mle *env);
void	key_echap(t_mle *env);
#endif
