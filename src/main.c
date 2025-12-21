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

	if (argc == 2 && check_name(argv[1], "mandelbrot"))
		ft_display_fractal(&fractal, argv[1], 0, 0);
	else if (argc == 4 && check_name(argv[1], "julia") && check_number(argv[2])
		&& check_number(argv[3]))
	{
		ft_display_fractal(&fractal, argv[1], ft_atodbl(argv[2]),
			ft_atodbl(argv[3]));
	}
	else
		ft_display_options();
	return (EXIT_SUCCESS);
}
