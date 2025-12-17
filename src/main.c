/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:17:55 by namatias          #+#    #+#             */
/*   Updated: 2025/12/14 14:23:15 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2 && check_args(argv[1], "mandelbrot"))
	{
		fractal.name = argv[1];
		//TODO : ft_display_mandelbrot();
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
		ft_printf("Mano Brot\n, %s\n", fractal.name);
	}
	else if (argc == 4 && check_args(argv[1], "julia"))
	{
		fractal.name = argv[1];
		//TODO : ft_display_julia();
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
		ft_printf("Mana Ju\n, %s\n", fractal.name);
	}
	else
		ft_display_options();
	return (EXIT_SUCCESS);
}
