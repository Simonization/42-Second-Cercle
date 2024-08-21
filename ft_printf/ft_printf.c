/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:20:16 by slangero          #+#    #+#             */
/*   Updated: 2024/07/10 18:34:56 by slangero         ###   ########.fr       */
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
/*

int	main(void)
{
	printf("Hello %s %d", "Simon" "18");
	ft_printf("Hello %s %d", "Nomis" "81");
	return (0);
}
void	print_numbers(const char *format, int count, ...)
{
	va_list	args;
	va_start(args, count);
	int	i;
	int	value;

printf("%s: ", format);
	i = 0;
	while (i < count)
	{
		value = va_arg(args, int);
		printf("%d ", value);
		i++;
	}
	va_end(args);
	printf("\n");
}

int	main(void)
{
	print_numbers("Numbers", 3, 10, 20, 30);
	return (0);
}
*/
/*
TEST:
va_start( va_list var, parameterN );
var is a variable of type arg_list (args for us)
parameterN is the named parameter preceding the first dynamic parameter 
(in our case, with printf, it would be the initial string) 
- in other words, it's the mandatory argument
Its purpose is to set the stage and 
define which elements will be stable and which will vary.

 you can start using and playing with your variable arguments. 
 This can be done with va_arg.
This macro allows access to the arguments of the variadic function. 
Each time va_arg is called, you move to the next argument. 

va_arg will take as argument first 
the list of dynamic arguments we had defined 
at the very beginning (va_list object) 
and the type of the variable of the next argument.

va_end() will free the allocated memory.
*/
