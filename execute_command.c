/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:12:30 by slangero          #+#    #+#             */
/*   Updated: 2024/09/20 17:20:13 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*execute_command(char *cmd, char **env)
{
	char	**table;
	char	**path;
	int		i;
	char	*result;

	path = NULL;
	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			table = ft_split(env[i], '=');
			if (!table)
				return (NULL);
			path = ft_split(table[1], ':');
			ft_free(table);
			if (!path)
				return (NULL);
			break ;
		}
		i++;
	}
	if (!path)
	{
		ft_printf("%s\n", "PATH environment variable not found\n");
		return (NULL);
	}
	result = access_path(path, cmd);
	ft_free(path);
	return (result);
}

char	*access_path(char **path, char *cmd)
{
	char	*tmp;
	char	*c_path;
	int		i;

	i = 0;
	tmp = ft_strjoin("/", cmd);
	if (!tmp)
		return (NULL);
	while (path[i])
	{
		c_path = ft_strjoin(path[i], tmp);
		if (!c_path)
		{
			free(tmp);
			return (NULL);
		}
		if (access(c_path, X_OK) == 0)
		{
			ft_printf("Executable found: %s\n", c_path);
			free(tmp);
			return (c_path);
		}
		free(c_path);
		i++;
	}
	free(tmp);
	return (NULL);
}
