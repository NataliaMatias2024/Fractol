/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:18:45 by namatias          #+#    #+#             */
/*   Updated: 2025/12/14 14:19:30 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "./Libs/libft.h"
# include "./minilibx-linux/mlx.h"

# define WIDTH	800;
# define HEIGHT	800;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_fractal
{
	void	*mlx_connection;//mlx_init()
	void	*mlx_window;	//mlx_new_window()

	char	*name;
	void	*img_ptr; //pointer to img struct
	char	*pixels_ptr; //pointer to the actual pixel
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_fractal;

int		check_args(const char *argv, const char *fractal);
void	ft_display_options(void);
void	fractal_init(t_fractal *fractal);
double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);

#endif