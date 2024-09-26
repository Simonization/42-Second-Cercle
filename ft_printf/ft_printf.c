/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:20:16 by slangero          #+#    #+#             */
/*   Updated: 2024/09/20 17:56:02 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char check)
{
	int	i;

	i = 0;
	if (check == 'c')
		i = print_char(va_arg(args, int));
	else if (check == 's')
		i = print_str(va_arg(args, char *));
	else if (check == 'd' || check == 'i')
		i = print_nbr(va_arg(args, int));
	else if (check == 'u')
		i = print_nbr_unsigned(va_arg(args, unsigned int));
	else if (check == 'x')
		i = print_hexa_min(va_arg(args, unsigned int));
	else if (check == 'X')
		i = print_hexa_max(va_arg(args, unsigned int));
	else if (check == 'p')
	{
		i += print_str("0x");
		i += print_adress(va_arg(args, unsigned long));
	}
	else if (check == '%')
		i = print_char('%');
	else
		return (-1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i = i + ft_format(args, *format);
			if (i == -1)
				return (-1);
		}
		else
			i = i + print_char(*format);
		if (i == -1)
			return (-1);
		format++;
	}
	va_end(args);
	return (i);
}
