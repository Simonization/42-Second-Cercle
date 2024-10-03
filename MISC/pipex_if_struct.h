// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pipex_if_struct.h                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/05/21 18:40:05 by slangero          #+#    #+#             */
// /*   Updated: 2024/10/03 18:33:24 by slangero         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #ifndef PIPEX_H
// # define PIPEX_H

// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <sys/wait.h>
// #include <errno.h>
// #include <string.h>
// #include <fcntl.h>
// #include <stdarg.h>
// #include "ft_printf/ft_printf.h"

// typedef struct s_pipex
// {
//     char    **argv;
//     char    **envp;
//     char    *infile;
//     char    *outfile;
//     char    **cmd1;
//     char    **cmd2;
//     int     pipe_fd[2];
//     pid_t   pid1;
//     pid_t   pid2;
// } t_pipex;

// /*********GNL
// char	*get_next_line(int fd);
// char	*ft_strchr(char *s);
// int		ft_strlen(const char *str);
// char	*ft_free(char **str, int n);
// char	*ft_strdup(char *s);
// char	*ft_substr(char *s, int start, int len);
// char	*read_line(int fd, char *stash, char *buffer);
// char	*ft_concat_stash_buffer(char *stash, char *buffer, int bytes_read);
// char	*ft_strjoin(char *str, char *buff);
// ************/

// #endif
