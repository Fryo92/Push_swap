/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:53:04 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/30 16:14:28 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_nbstr(char const *str, char c)
{
	int	i;
	int	comp;

	i = 0;
	comp = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			comp++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (comp);
}

static char	*ft_dup(char const *str, char c)
{
	char	*dest;
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		size++;
	}
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}	
	dest[i] = 0;
	return (dest);
}

char	**free_all(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**ret;
	char	*word;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	ret = (char **)malloc(sizeof(char *) * (ft_nbstr(s, c) + 1));
	if (!ret)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{	
			word = ft_dup(s, c);
			ret[i] = word;
			if (!ret[i++])
				return (free_all(ret));
			s = s + ft_strlen(word);
		}
	}
	ret[i] = NULL;
	return (ret);
}
