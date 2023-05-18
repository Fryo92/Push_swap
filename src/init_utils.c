/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:54:53 by abiddane          #+#    #+#             */
/*   Updated: 2023/02/03 11:20:25 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isduplicate2(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
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

long long int	ft_atoi(const char *nptr)
{
	int					i;
	int					comp;
	long long int		n;

	i = 0;
	comp = 1;
	n = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			comp *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + nptr[i] - '0';
		i++;
	}
	return (n * comp);
}

void	ft_lstadd_back(t_pile **lst, t_pile *new)
{
	t_pile	*stock;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			stock = pile_last(*lst);
			stock->next = new;
		}
	}	
}

t_pile	*new_pile(int value)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	push_init(t_pile **pile)
{
	t_pile	*tmp;
	int		size;

	tmp = *pile;
	size = ft_lstsize(*pile);
	while (*pile)
	{
		if ((*pile)->index == size - 1 || (*pile)->index == size - 2
			|| (*pile)->index == size - 3)
			(*pile)->push = 1;
		else
			(*pile)->push = 0;
		*pile = (*pile)->next;
	}
	*pile = tmp;
}
