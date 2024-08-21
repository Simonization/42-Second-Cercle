/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:32:02 by slangero          #+#    #+#             */
/*   Updated: 2024/07/16 16:32:20 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// INCLUDES
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_format(va_list args, char check);

int	print_nbr(int nbr);
int	print_nbr_unsigned(unsigned int nbr);
int	print_hexa_min(unsigned int nbr);
int	print_hexa_max(unsigned int nbr);

int	print_char(char c);
int	print_str(char *s);

int	print_adress(unsigned long nbr);

#endif
