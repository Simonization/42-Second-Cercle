/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:17:07 by slangero          #+#    #+#             */
/*   Updated: 2024/07/10 18:02:34 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		i += print_str("-2147483648");
		return (i);
	}
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr *= -1;
		i++;
	}
	if (nbr >= 10)
		i += print_nbr(nbr / 10);
	i += print_char(nbr % 10 + 48);
	if (i == -1)
		return (-1);
	return (i);
}

int	print_nbr_unsigned(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else if (nbr >= 10)
	{
		i += print_nbr_unsigned(nbr / 10);
		i += print_char(nbr % 10 + 48);
	}
	else
		i += print_char(nbr + 48);
	if (i == -1)
		return (-1);
	return (i);
}

int	print_hexa_min(unsigned int nbr)
{
	int		i;
	char	*hexa;

	i = 0;
	hexa = "0123456789abcdef";
	if (nbr >= 16)
	{
		i += print_hexa_min(nbr / 16);
		i += print_hexa_min(nbr % 16);
	}
	else
		i += print_char(hexa[nbr % 16]);
	if (i == -1)
		return (-1);
	return (i);
}

int	print_hexa_max(unsigned int nbr)
{
	int		i;
	char	*hexa;

	i = 0;
	hexa = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		i += print_hexa_max(nbr / 16);
		i += print_hexa_max(nbr % 16);
	}
	else
		i += print_char(hexa[nbr % 16]);
	if (i == -1)
		return (-1);
	return (i);
}
