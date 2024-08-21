/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:45 by slangero          #+#    #+#             */
/*   Updated: 2024/07/10 18:36:03 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_adress(unsigned long nbr)
{
	int		i;
	char	*hexa;

	i = 0;
	hexa = "0123456789abcdef";
	if (nbr >= 16)
	{
		i += print_adress(nbr / 16);
		i += print_adress(nbr % 16);
	}
	else
		i += print_char(hexa[nbr % 16]);
	return (i);
}
