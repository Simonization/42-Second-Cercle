/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_exec_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:33:48 by slangero          #+#    #+#             */
/*   Updated: 2024/09/26 11:50:10 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*create_full_path(const char *dir, const char *cmd)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin("/", cmd);
	if (!tmp)
		return (NULL);
	full_path = ft_strjoin(dir, tmp);
	free(tmp);
	if (!full_path)
		return (NULL);
	return (full_path);
}

int	ft_check_if_executable(char *full_path)
{
	if (access(full_path, X_OK) == 0)
		return (1);
	else
		return (0);
}
