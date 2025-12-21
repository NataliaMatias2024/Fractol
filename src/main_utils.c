/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:05:06 by namatias          #+#    #+#             */
/*   Updated: 2025/12/20 22:27:21 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_name(const char *argv, const char *fractal)
{
	int			flag_ok;
	size_t		len_argv;
	size_t		len_fractal;

	flag_ok = 0;
	if (argv == NULL || fractal == NULL)
		return (flag_ok);
	len_argv = ft_strlen(argv);
	len_fractal = ft_strlen(fractal);
	if (len_argv == len_fractal && (ft_strncmp(argv, fractal, len_argv) == 0))
		flag_ok = 1;
	return (flag_ok);
}

int	check_number(char *argv)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	while (argv[i])
	{
		if (argv[i] == '-')
			i++;
		else if (ft_isdigit(argv[i]) || argv[i] == '.')
		{
			if (argv[i] == '.')
				dot += 1;
			i++;
		}
		else
			return (0);
	}
	if (dot > 1)
		return (0);
	return (1);
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
	ft_putstr_fd("| ./fractol julia <real> <i>             |\n", 1);
	ft_putstr_fd("|                                        |\n", 1);
	ft_putstr_fd("|-----[ Example of Julia's fractal ]-----|\n", 1);
	ft_putstr_fd("| To execute correctly, use the commands:|\n", 1);
	ft_putstr_fd("|----------------------------------------|\n", 1);
	ft_putstr_fd("| ./fractol julia -0.4 0.6               |\n", 1);
	ft_putstr_fd("| ./fractol julia  0.285 0.01            |\n", 1);
	ft_putstr_fd("| ./fractol julia -0.835 -0.2321         |\n", 1);
	ft_putstr_fd("└────────────────────────────────────────┘\n", 1);
}
