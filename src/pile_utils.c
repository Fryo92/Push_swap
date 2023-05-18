/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:39:15 by abiddane          #+#    #+#             */
/*   Updated: 2023/02/02 12:38:04 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*pile_last(t_pile *pile)
{
	while (pile && pile->next != NULL)
		pile = pile->next;
	return (pile);
}

t_pile	*pile_before_last(t_pile *pile)
{
	while (pile && pile->next && pile->next->next)
		pile = pile->next;
	return (pile);
}

int	ft_lstsize(t_pile *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}

int	find_value(t_pile *pile, int value)
{
	t_pile	*tmp;
	int		comp;

	comp = 0;
	tmp = pile;
	while (pile->value != value)
	{
		pile = pile->next;
		comp++;
	}
	pile = tmp;
	return (comp);
}

int	find_index(t_pile *pile, int index)
{
	t_pile	*tmp;
	int		comp;

	comp = 0;
	tmp = pile;
	while (pile->index != index)
	{
		pile = pile->next;
		comp++;
	}
	pile = tmp;
	return (comp);
}
