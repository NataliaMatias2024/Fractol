/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:31:29 by namatias          #+#    #+#             */
/*   Updated: 2025/12/17 15:58:25 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img_ptr, 0, 0);
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = 0.0;
	z.y = 0.0;

	c.x = map(x, -2, +2, WIDTH);
	c.y = map(y, +2, -2, HEIGHT);
	i = 0;
	while (i < fractal->iterations_definitions)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->iterations_definitions);
			my_pixel_display(x, y, fractal, color);
			return ;
		}
		i++;
	}
	my_pixel_display(x, y, fractal, PURPLE);
}

void	my_pixel_display(int x, int y, t_fractal *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
