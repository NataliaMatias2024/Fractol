/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:12:52 by namatias          #+#    #+#             */
/*   Updated: 2025/12/20 10:46:46 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		ft_close(fractal);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_plus || keysym == XK_KP_Add)
		fractal->iterations_definitions += 10;
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
		fractal->iterations_definitions -= 10;
	ft_fractal_render(fractal);
	return (0);
}

int	ft_mouse(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button5)
		fractal->zoom *= 1.05;
	else if (button == Button4)
		fractal->zoom *= 0.95;
	ft_fractal_render(fractal);
	return (0);
}

int	ft_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->connection, fractal->img_ptr);
	mlx_destroy_window(fractal->connection, fractal->window);
	mlx_destroy_display(fractal->connection);
	free(fractal->connection);
	exit(EXIT_SUCCESS);
}