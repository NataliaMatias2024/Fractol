/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:44:51 by namatias          #+#    #+#             */
/*   Updated: 2025/12/14 12:31:10 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_x(unsigned int c)
{
	int				i;
	unsigned int	result;

	i = 0;
	if (c > 15)
		i = i + ft_put_x(c / 16);
	result = c % 16;
	if (result <= 9)
		i = i + ft_put_c(result + '0');
	if (result == 10)
		i = i + ft_put_c('a');
	else if (result == 11)
		i = i + ft_put_c('b');
	else if (result == 12)
		i = i + ft_put_c('c');
	else if (result == 13)
		i = i + ft_put_c('d');
	else if (result == 14)
		i = i + ft_put_c('e');
	else if (result == 15)
		i = i + ft_put_c('f');
	return (i);
}
