/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:31:29 by namatias          #+#    #+#             */
/*   Updated: 2025/12/20 09:09:10 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	c.x = fractal->julia_x;
	c.y = fractal->julia_y;
	i = 0;
	while (i < fractal->iterations_definitions)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = ft_interpolate_color(DARK_GREEN, GOLD, (double)i / fractal->iterations_definitions);
			ft_my_pixel_display(x, y, fractal, color);
			return ;
		}
		i++;
	}
	ft_my_pixel_display(x, y, fractal, BLUE);
}

static void	set_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = 0.0;
	z.y = 0.0;
	c.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	i = 0;
	while (i < fractal->iterations_definitions)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLUE, GREEN, fractal->iterations_definitions);
			ft_my_pixel_display(x, y, fractal, color);
			return ;
		}
		i++;
	}
	ft_my_pixel_display(x, y, fractal, BLACK);
}

void	ft_my_pixel_display(int x, int y, t_fractal *img, int color)
{
	char	*pixel;

	pixel = img->pixels_ptr + (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	ft_fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;
	int	is_mandel;

	y = 0;
	is_mandel = check_args(fractal->name, "mandelbrot");
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (is_mandel == 1)
				set_mandelbrot(x, y, fractal);
			else
				set_julia(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->connection, fractal->window, fractal->img_ptr, 0, 0);
}
