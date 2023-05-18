/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:40:57 by abiddane          #+#    #+#             */
/*   Updated: 2023/02/06 14:35:06 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_pile **pile)
{
	while (!ft_sorted(*pile))
	{
		if ((*pile)->value == get_max(*pile))
			ft_ra(pile);
		if (pile_last(*pile)->value != get_max(*pile))
			ft_rra(pile);
		if ((*pile)->value > (*pile)->next->value)
			ft_sa(*pile);
	}
}

void	sort_five(t_pile **pile_a, t_pile **pile_b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (find_value(*pile_a, get_min(*pile_a)) < ft_lstsize(*pile_a) / 2)
		{
			while ((*pile_a)->value != get_min(*pile_a))
				ft_ra(pile_a);
		}
		else
		{
			while ((*pile_a)->value != get_min(*pile_a))
				ft_rra(pile_a);
		}
		ft_pb(pile_a, pile_b);
		i++;
	}
	sort_three(pile_a);
	ft_pa(pile_a, pile_b);
	ft_pa(pile_a, pile_b);
}
