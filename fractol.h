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

int		check_args(char *argv);
void	ft_display_options(void);

#endif