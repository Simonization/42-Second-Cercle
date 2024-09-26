/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:08:56 by slangero          #+#    #+#             */
/*   Updated: 2024/09/26 11:49:29 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **table)
{
	int	i;

	if (table == NULL)
		return ;
	i = 0;
	while (table[i] != NULL)
	{
		free(table[i]);
		table[i] = NULL;
		i++;
	}
	free(table);
	table = NULL;
}

char	*verify(char *exec_path, char *split_cmd)
{
	if (!exec_path)
	{
		ft_putstr_fd("Command not found: ", STDERR_FILENO);
		ft_putstr_fd(&split_cmd[0], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		//ft_free(&split_cmd);
	}
	if (access(exec_path, F_OK) == -1)
	{
		ft_putstr_fd("Error: File does not exist: ", STDERR_FILENO);
		ft_putstr_fd(exec_path, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		//free(exec_path);
		//ft_free(&split_cmd);
	}
	if (access(exec_path, X_OK) == -1)
	{
		ft_putstr_fd("Error: Permission denied: ", STDERR_FILENO);
		ft_putstr_fd(exec_path, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		//free(exec_path);
		//ft_free(&split_cmd);
	}
	return (NULL);
}

//void	ft_free_strv()