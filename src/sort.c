/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:29:21 by abiddane          #+#    #+#             */
/*   Updated: 2023/02/08 13:11:23 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk1(t_pile **pile_a, int chunk_size)
{
	int		comp;
	t_pile	*tmp;

	comp = 0;
	tmp = *pile_a;
	while ((*pile_a)->index >= chunk_size)
	{
		*pile_a = (*pile_a)->next;
		comp++;
	}
	*pile_a = tmp;
	return (comp);
}

int	chunk2(t_pile **pile_a, int chunk_size)
{
	int		comp;
	t_pile	*tmp;
	int		left;

	comp = 0;
	tmp = *pile_a;
	left = chunk_left(pile_a, chunk_size);
	while (comp < left)
	{
		if ((*pile_a)->index < chunk_size)
			comp++;
		*pile_a = (*pile_a)->next;
	}
	comp = 0;
	while (*pile_a)
	{
		*pile_a = (*pile_a)->next;
		comp++;
	}
	*pile_a = tmp;
	return (comp);
}

void	push_to_b(t_pile **pile_a, t_pile **pile_b, int chunk_size)
{
	while (ft_lstsize(*pile_a) != 3)
	{
		while (chunk_left(pile_a, chunk_size) != 0)
		{
			while ((*pile_a)->index >= chunk_size)
			{
				if (chunk1(pile_a, chunk_size) <= chunk2(pile_a, chunk_size))
					ft_ra(pile_a);
				else
					ft_rra(pile_a);
			}
			if ((*pile_a)->push == 0)
				ft_pb(pile_a, pile_b);
			else
				ft_ra(pile_a);
			if ((*pile_b)->index < chunk_size / 2)
				ft_rb(pile_b);
		}
		get_index(*pile_a);
	}
}

void	push_to_a(t_pile **pile_a, t_pile **pile_b)
{
	int	size;

	while (*pile_b)
	{
		size = ft_lstsize(*pile_b);
		while ((*pile_b)->value != get_max(*pile_b))
		{
			if (find_value(*pile_b, get_max(*pile_b)) < size / 2)
				ft_rb(pile_b);
			else
				ft_rrb(pile_b);
		}
		ft_pa(pile_a, pile_b);
	}
}

void	sort_pile(t_pile **pile_a, t_pile **pile_b)
{
	int	size;
	int	chunk;
	int	chunk_size;

	chunk = set_chunk(pile_a);
	size = ft_lstsize(*pile_a);
	chunk_size = size / chunk;
	push_init(pile_a);
	push_to_b(pile_a, pile_b, chunk_size);
	sort_three(pile_a);
	push_to_a(pile_a, pile_b);
}
