/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_charstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:17:33 by slangero          #+#    #+#             */
/*   Updated: 2024/07/10 17:55:41 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	ssize_t	result;

	result = write (1, &c, 1);
	if (result == -1)
		return (-1);
	return (1);
}

int	print_str(char *s)
{
	int		i;
	ssize_t	result;

	i = 0;
	if (!s)
	{
		result = write (1, "(null)", 6);
		if (result == -1)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		result = write (1, &s[i], 1);
		if (result == -1)
			return (-1);
		i++;
	}
	return (i);
}

/*
int	putpercent(char c)
{
	return ();
}
*/