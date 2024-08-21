/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:51:51 by slangero          #+#    #+#             */
/*   Updated: 2024/07/10 17:28:42 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	n;

	n = 5;
	ft_printf("yo %i, %p\n", n, &n);
	printf("Hello %s, %d", "Simon", 18);
	ft_printf("Hello %s, %d", "Nomis", 81);
	ft_printf("Numbers %d %d %d %d", 3, 10, 20, 30);
	return (0);
}
// int	ft_add(int *a)
// {
// 	*a += 2;
// 	return (1);
// }
// int	main(int argc, char *argv[])
// {
// 	int	n;
//
// 	(void) argc;
// 	(void) argv;
// 	n = 5;
// 	ft_add(&n);
// 	ft_printf("yo %i, %p\n", n, &n);
// 	printf("yo %i, %p\n", n, &n);
// 	return (0);
// }