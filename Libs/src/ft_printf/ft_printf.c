/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:46:26 by namatias          #+#    #+#             */
/*   Updated: 2025/12/14 12:33:17 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_arg(const char c, va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count = count + ft_check_arg(format[i], ap);
		}
		else
			count = count + ft_put_c(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

static int	ft_check_arg(const char c, va_list ap)
{
	if (c == 'p')
		return (ft_put_p(va_arg(ap, void *)));
	else if (c == 'c')
		return (ft_put_c(va_arg(ap, int)));
	else if (c == 's')
		return (ft_put_s(va_arg(ap, char *)));
	else if ((c == 'd') || (c == 'i'))
		return (ft_put_nbr(va_arg(ap, int)));
	else if (c == 'x')
		return (ft_put_x(va_arg(ap, unsigned int)));
	else if (c == 'u')
		return (ft_put_nbr_u(va_arg(ap, unsigned int)));
	else if (c == 'X')
		return (ft_put_x_upper(va_arg(ap, unsigned int)));
	else if (c == '%')
		return (ft_put_c(c));
	return (0);
}
