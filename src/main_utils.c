/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:05:06 by namatias          #+#    #+#             */
/*   Updated: 2025/12/15 17:46:59 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_args(const char *argv, const char *fractal)
{
	int			flag_ok;
	size_t		len_argv;
	size_t		len_fractal;

	flag_ok = 0;
	len_argv = ft_strlen(argv);
	len_fractal = ft_strlen(fractal);
	if (len_argv == len_fractal && (ft_strncmp(argv, fractal, len_argv) == 0))
		flag_ok = 1;
	return (flag_ok);
}

void	ft_display_options(void)
{
	ft_putstr_fd("┌────────────────────────────────────────┐\n", 1);
	ft_putstr_fd("| 42school                               |\n", 1);
	ft_putstr_fd("|                                        |\n", 1);
	ft_putstr_fd("|---------------[ Options ]--------------|\n", 1);
	ft_putstr_fd("| To execute correctly, use the commands:|\n", 1);
	ft_putstr_fd("|----------------------------------------|\n", 1);
	ft_putstr_fd("| ./fractol mandelbrot                   |\n", 1);
	ft_putstr_fd("| ./fractol julia <X> <Y>                |\n", 1);
	ft_putstr_fd("└────────────────────────────────────────┘\n", 1);
}