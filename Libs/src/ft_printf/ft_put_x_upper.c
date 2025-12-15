/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x_upper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 01:27:04 by namatias          #+#    #+#             */
/*   Updated: 2025/12/14 12:30:27 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_x_upper(unsigned int c)
{
	int				i;
	unsigned int	result;

	i = 0;
	if (c > 15)
		i = i + ft_put_x_upper(c / 16);
	result = c % 16;
	if (result <= 9)
		i = i + ft_put_c(result + '0');
	else if (result == 10)
		i = i + ft_put_c ('A');
	else if (result == 11)
		i = i + ft_put_c ('B');
	else if (result == 12)
		i = i + ft_put_c ('C');
	else if (result == 13)
		i = i + ft_put_c ('D');
	else if (result == 14)
		i = i + ft_put_c ('E');
	else if (result == 15)
		i = i + ft_put_c ('F');
	return (i);
}
