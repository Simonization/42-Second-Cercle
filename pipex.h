/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:58:37 by slangero          #+#    #+#             */
/*   Updated: 2024/10/07 20:17:37 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>
# include "utils.h"
# include "ft_printf.h"

void	first_fork(char *command, char *infile, char **env, int *fd);
void	second_fork(char *command, char *outfile, char **env, int *fd);

int		parent_process(char **av, char **env);

void	redirection_io_first(int *fd, const char *infile);
void	redirection_io_second(int *fd, const char *outfile);

void	first_cmd(char *cmd, char **env, int *fd, char *infile);
void	sec_cmd(char *cmd, char **env, int *fd, char *outfile);

char	*find_executable_path(char *cmd, char **env);
void	execute_command(char *cmd, char **env);

char	**ft_extract_cmd(char *cmd);
char	**ft_extract_env_path(char **env);
char	*ft_search_env_path(char *cmd, char **env_path);

char	*create_full_path(const char *dir, const char *cmd);
int		ft_check_if_executable(char *full_path);

void	ft_free(char **table);
char	*verify(char *exec_path);

#endif