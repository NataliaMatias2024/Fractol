/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 01:35:59 by namatias          #+#    #+#             */
/*   Updated: 2025/12/14 12:30:30 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_put_longx(size_t c);

int	ft_put_p(void *c)
{
	int		i;
	size_t	address;

	i = 0;
	if (!c)
	{
		i = i + ft_put_s("(nil)");
		return (i);
	}
	else
	{
		i = i + ft_put_s("0x");
		address = (size_t)c;
		i = i + ft_put_longx(address);
	}
	return (i);
}

static int	ft_put_longx(size_t c)
{
	int	i;
	int	digit;

	i = 0;
	if (c > 15)
		i = i + ft_put_longx(c / 16);
	digit = c % 16;
	if (digit <= 9)
		i = i + ft_put_c(digit + '0');
	else if (digit == 10)
		i = i + ft_put_c('a');
	else if (digit == 11)
		i = i + ft_put_c('b');
	else if (digit == 12)
		i = i + ft_put_c('c');
	else if (digit == 13)
		i = i + ft_put_c('d');
	else if (digit == 14)
		i = i + ft_put_c('e');
	else if (digit == 15)
		i = i + ft_put_c('f');
	return (i);
}
