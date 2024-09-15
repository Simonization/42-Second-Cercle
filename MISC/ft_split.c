#include <stdio.h>
#include "libft.h"

int	word_count(const char *str, char sep)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] == sep && str[i])
			i++;
		if (str[i] != sep && str[i])
			nb++;
		while (str[i] != sep && str[i])
			i++;
	}
	return (nb);
}

void	*ft_free_all(char	**array, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}
/* static void? et return NULL?*/

char	*fill_str(const char *str, char sep, int widx)
{
	int	i;
	int	c;
	int	start;

	i = 0;
	c = 0;
	while (str[i] && c < widx)
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i] != sep)
			c++;
		while (str[i] && str[i] != sep)
			i++;
	}
	while (str[i] == sep && str[i])
		i++;
	start = i;
	while (str[i] != sep && str[i])
		i++;
	return (ft_substr(str, start, i - start));
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		x;	
	char	**table;

	if (!s)
		return (NULL);
	table = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!table)
		return (NULL);
	i = 0;
	x = 0;
	while (x < word_count(s, c))
	{
		table[x] = fill_str(s, c, x);
		if (!table[x])
			return (ft_free_all(table, x));
		x++;
	}
	table[x] = NULL;
	return (table);
}