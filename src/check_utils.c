/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:20:07 by abiddane          #+#    #+#             */
/*   Updated: 2023/01/24 13:33:44 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}

int	skip_minus_s1(char *s1, char *s2, int i)
{
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '-' && s2[j] == '-')
	{
		i++;
		j++;
	}
	while (s1[i] == '0')
	{
		if (s2[j] != '0')
			i++;
		else
		{
			i++;
			j++;
		}	
	}
	return (i);
}

int	skip_minus_s2(char *s1, char *s2, int j)
{
	int	i;

	i = 0;
	j = 0;
	if (s2[j] == '-' && s1[i] == '-')
	{
		i++;
		j++;
	}
	while (s2[j] == '0')
	{
		if (s1[i] != '0')
			j++;
		else
		{
			i++;
			j++;
		}
	}
	return (j);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	j = skip_minus_s2(s1, s2, j);
	i = skip_minus_s1(s1, s2, i);
	while (s1[i] == '+' || s1[i] == '0')
	{
		if (s2[j] != '+' || s2[j] != '0')
			i++;
	}
	while (s2[j] == '+' || s2[j] == '0')
	{
		if (s1[i] != '+' || s1[i] != '0')
			j++;
	}
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
