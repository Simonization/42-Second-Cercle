/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:12:51 by slangero          #+#    #+#             */
/*   Updated: 2024/10/03 23:41:49 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_args(int ac)
{
	if (ac != 5)
	{
		ft_printf("%s\n", "invalid number of arguments");
		return (1);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int	result;

	if (check_args(ac) != 0)
	{
		return (1);
	}
	result = parent_process(av, env);
	if (result != 0)
	{
		ft_printf("%s\n", "Error occurred in parent process");
		return (1);
	}
	return (0);
}
