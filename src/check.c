/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:32:37 by abiddane          #+#    #+#             */
/*   Updated: 2023/02/17 13:15:20 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (ft_issign(str[i]) && str[i + 1])
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		return (0);
	return (1);
}

int	ft_isduplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && !ft_strcmp(av[i], av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_iszero(char *str)
{
	int	i;

	i = 0;
	if (ft_issign(str[i]))
		i++;
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	check_arg(int ac, char **av)
{
	int	i;
	int	comp;

	i = 1;
	comp = 0;
	if (!ft_isduplicate(av))
		return (0);
	while (i < ac)
	{
		if (ft_strlen(av[i]) > 13)
			return (0);
		if (!ft_isnumber(av[i]))
			return (0);
		comp += ft_iszero(av[i]);
		i++;
	}
	if (comp > 1)
		return (0);
	return (1);
}

int	check_arg_tab(int ac, char **av)
{
	int	i;
	int	comp;

	i = 0;
	comp = 0;
	if (!av[i])
		return (0);
	if (!ft_isduplicate2(av))
		return (0);
	while (i < ac)
	{
		if (ft_strlen(av[i]) > 13)
			return (0);
		if (!ft_isnumber(av[i]))
			return (0);
		comp += ft_iszero(av[i]);
		i++;
	}
	if (comp > 1)
		return (0);
	return (1);
}
