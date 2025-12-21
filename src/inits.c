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
	ft_putstr_fd("Error: unable to allocate memory", 2);
	exit(EXIT_FAILURE);
}

static void	ft_data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definitions = 100;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	ft_events_init(t_fractal *fractal)
{
	mlx_hook(fractal->window, KeyPress, KeyPressMask, ft_key, fractal);
	mlx_hook(fractal->window, ButtonPress, ButtonPressMask, ft_mouse, fractal);
	mlx_hook(fractal->window, DestroyNotify, StructureNotifyMask, ft_close,
		fractal);
}

void	ft_fractal_init(t_fractal *fractal)
{
	fractal->connection = mlx_init();
	if (fractal->connection == NULL)
		malloc_error();
	fractal->window = mlx_new_window(fractal->connection, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->window == NULL)
	{
		mlx_destroy_display(fractal->connection);
		free(fractal->connection);
		malloc_error();
	}
	fractal->img_ptr = mlx_new_image(fractal->connection, WIDTH, HEIGHT);
	if (fractal->img_ptr == NULL)
	{
		mlx_destroy_window(fractal->connection, fractal->window);
		mlx_destroy_display(fractal->connection);
		free(fractal->connection);
		malloc_error();
	}
	fractal->pixels_ptr = mlx_get_data_addr(fractal->img_ptr,
			&fractal->bits_per_pixel, &fractal->line_len, &fractal->endian);
	ft_events_init(fractal);
	ft_data_init(fractal);
}

void	ft_display_fractal(t_fractal *fractal, char *name, double x, double y)
{
	fractal->name = name;
	fractal->julia_x = x;
	fractal->julia_y = y;
	ft_fractal_init(fractal);
	ft_fractal_render(fractal);
	mlx_loop(fractal->connection);
}
