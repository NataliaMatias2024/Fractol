/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:07:32 by namatias          #+#    #+#             */
/*   Updated: 2025/12/16 17:07:32 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH,
										HEIGHT, fractal->name); title:
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection); mlx_ptr:
		free(fractal->mlx_connection); ptr:
		malloc_error();		
	}
	fractal->img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, 
								     HEIGHT); width: height:
	if (fractal->img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window); mlx_ptr: win_ptr:
		mlx_destroy_display(fractal->mlx_connection); mlx_ptr:
		free(fractal->mlx_connection); ptr:
		malloc_error();
	}
	fractal->img_ptr = mlx_get_data_addr(fractal->img_ptr, fractal->bits_per_pixel, 
										fractal->line_len, fractal->endian)
	//events_init(); //TODO
	//data_init(); //TODO
}

void handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;

	z.x = 0.0;
	z.y = 0.0;

	c.x = map(x, -2, +2, 0, 799);
	c.y = map(y, +2, -2, 0, 799);

	while ()
	{
		z = sum_complex(square_complex(z), c);
		if ()
		{
			my_pixel_display(); //TODO
			return ;
		}
	}
}

void fractal_render(t_fractal *fractal)
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
}