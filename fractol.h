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
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH	800
# define HEIGHT	800
# define BLACK  0x000000
# define WHITE  0xFFFFFF
# define PURPLE 0X8b3cd4ff
# define ORANGE 0xFF6600
# define RED    0xFF0000
# define GREEN  0x00FF00
# define BLUE   0x0000FF
# define DARK_GREEN  0x152D02
# define GOLD        0xFFD700
# define DARK_BLUE   0x000080

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_fractal
{
	char	*name;
	void	*connection;
	void	*window;

	void	*img_ptr;
	char	*pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;

	double	escape_value;
	int		iterations_definitions;
	double	shift_y;
	double	shift_x;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);

int			check_name(const char *argv, const char *fractal);
int			check_number(char *argv);
void		ft_display_options(void);
void		ft_fractal_init(t_fractal *fractal);
void		ft_fractal_render(t_fractal *fractal);
void		ft_my_pixel_display(int x, int y, t_fractal *img, int color);
void		ft_display_fractal(t_fractal *fractal, char *name,
				double x, double y);
int			ft_interpolate_color(int color1, int color2, double fraction);

int			ft_close(t_fractal *fractal);
int			ft_mouse(int button, int x, int y, t_fractal *fractal);
int			ft_key(int keysym, t_fractal *fractal);

#endif