/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:12:30 by slangero          #+#    #+#             */
/*   Updated: 2024/09/26 11:49:10 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_extract_cmd(char *cmd)
{
	char	**split_cmd;

	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd)
	{
		perror("Error splitting command");
		return (NULL);
	}
	return (split_cmd);
}

char	**ft_extract_env_path(char **env)
{
	char	**env_path;
	int		i;

	env_path = NULL;
	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == EXIT_SUCCESS)
		{
			env_path = ft_split(env[i] + 5, ':');
			if (!env_path)
				return (NULL);
			break ;
		}
		i++;
	}
	return (env_path);
}

char	*ft_search_env_path(char *cmd, char **env_path)
{
	char	*full_path;
	int		i;

	i = 0;
	while (env_path[i])
	{
		full_path = create_full_path(env_path[i], cmd);
		//fprintf(stderr, "the executable is %s\n", full_path);
		if (!full_path)
			return (NULL);
		if (ft_check_if_executable(full_path))
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

/*
	- split cmd --> find path --> prepend path to cmd --> check if exec
*/

/*
	- char *cmd = split_cmd()
	- char **env_path = find_and_split_env_path()
	- path_to_exec = find_executable(cmd, path)
					--> if strchr('\', cmd)
						--> acces (X_OK) ?
						while (path)
						--> prepend path to cmd 
						--> access (X_OK) ? if yes return, 
						if not free and keep looping
*/
/*
 if (!path)
            {
                perror("Error splitting PATH");
                return NULL;


    if (!path)
    {
        fprintf(stderr, "PATH not found in environment\n");
    }
*/

/*
	permissions des files
	existence des files
	permissions des execs
	existence des execs
	....
*/