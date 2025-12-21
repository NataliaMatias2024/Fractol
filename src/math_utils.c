/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:17:44 by namatias          #+#    #+#             */
/*   Updated: 2025/12/21 09:49:31 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double old_min, double old_max, double max)
{
	return ((old_max - old_min) * unscaled_num / max + old_min);
}

t_complex	sum_complex(t_complex z1, t_complex c)
{
	t_complex	result;

	result.x = z1.x + c.x;
	result.y = z1.y + c.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

int	ft_interpolate_color(int color1, int color2, double fraction)
{
	int	r;
	int	g;
	int	b;

	r = ((color1 >> 16) & 0xFF) + fraction * (((color2 >> 16) & 0xFF)
			- ((color1 >> 16) & 0xFF));
	g = ((color1 >> 8) & 0xFF) + fraction * (((color2 >> 8) & 0xFF)
			- ((color1 >> 8) & 0xFF));
	b = (color1 & 0xFF) + fraction * ((color2 & 0xFF) - (color1 & 0xFF));
	return ((r << 16) | (g << 8) | b);
}
