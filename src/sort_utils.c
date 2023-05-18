/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:28:51 by abiddane          #+#    #+#             */
/*   Updated: 2023/02/08 12:25:46 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_pile *pile)
{
	int		max;

	max = pile->value;
	while (pile)
	{
		if (max < pile->value)
			max = pile->value;
		pile = pile->next;
	}
	return (max);
}

int	get_min(t_pile *pile)
{
	int		min;

	min = pile->value;
	while (pile)
	{
		if (min > pile->value)
			min = pile->value;
		pile = pile->next;
	}
	return (min);
}

int	set_chunk(t_pile **pile_a)
{
	int	chunk;

	if (ft_lstsize(*pile_a) <= 10)
		chunk = 2;
	else if (ft_lstsize(*pile_a) <= 150)
		chunk = 4;
	else
		chunk = 10;
	return (chunk);
}

int	chunk_left(t_pile **pile_a, int chunk_size)
{
	int		comp;
	t_pile	*tmp;

	tmp = *pile_a;
	comp = 0;
	while (*pile_a)
	{
		if ((*pile_a)->index < chunk_size && (*pile_a)->push == 0)
			comp++;
		*pile_a = (*pile_a)->next;
	}
	*pile_a = tmp;
	return (comp);
}
