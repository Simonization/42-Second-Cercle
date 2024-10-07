/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:24:08 by slangero          #+#    #+#             */
/*   Updated: 2024/10/07 20:22:59 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *s)
{
	char	*dupstr;
	int		len;
	int		i;

	len = 0;
	while (s[len])
		len++;
	dupstr = malloc(sizeof(char) * (len + 1));
	if (!dupstr)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		dupstr[i] = s[i];
		i++;
	}
	dupstr[i] = '\0';
	return (dupstr);
}
