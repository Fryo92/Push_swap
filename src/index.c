/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:08:40 by abiddane          #+#    #+#             */
/*   Updated: 2023/02/08 13:41:56 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			j = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = j;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}

int	*get_sort_tab(t_pile **pile_a)
{
	t_pile	*tmp;
	int		*tab;
	int		i;
	int		size;

	i = 0;
	tmp = *pile_a;
	size = ft_lstsize(*pile_a);
	tab = malloc(sizeof(int) * (ft_lstsize(*pile_a)));
	if (!tab)
		kill_exe(pile_a, NULL, NULL);
	while (*pile_a)
	{
		tab[i] = (*pile_a)->value;
		i++;
		*pile_a = (*pile_a)->next;
	}
	sort_tab(tab, size);
	*pile_a = tmp;
	return (tab);
}

void	get_index(t_pile *pile_a)
{
	t_pile	*tmp;
	int		*tab;
	int		i;
	int		size;

	size = ft_lstsize(pile_a);
	tmp = pile_a;
	tab = get_sort_tab(&pile_a);
	i = 0;
	while (pile_a)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] == pile_a->value)
				pile_a->index = i;
			i++;
		}
		pile_a = pile_a->next;
	}
	pile_a = tmp;
	free(tab);
}
