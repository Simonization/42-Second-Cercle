/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:08:56 by slangero          #+#    #+#             */
/*   Updated: 2024/10/02 22:00:11 by slangero         ###   ########.fr       */
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

char	*verify(char *exec_path)
{
	if (!exec_path)
	{
		perror(NULL);
		exit(1);
	}
	if (access(exec_path, F_OK) == -1)
	{
		perror(NULL);
		exit(1);
	}
	if (access(exec_path, X_OK) == -1)
	{
		perror(NULL);
		exit(1);
	}
	return (NULL);
}
