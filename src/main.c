/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:07:51 by abiddane          #+#    #+#             */
/*   Updated: 2023/02/06 13:12:00 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_pile *pile_a)
{
	while (pile_a->next)
	{
		if (pile_a->value > pile_a->next->value)
			return (0);
		pile_a = pile_a->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	int		i;

	pile_b = NULL;
	if (ac > 1)
	{
		pile_a = ft_init(ac, av);
		if (ft_sorted(pile_a))
		{
			free_pile(&pile_a);
			return (1);
		}
		if (ft_lstsize(pile_a) <= 3)
			sort_three(&pile_a);
		else if (ft_lstsize(pile_a) <= 5)
			sort_five(&pile_a, &pile_b);
		else
			sort_pile(&pile_a, &pile_b);
		free_pile(&pile_a);
		free_pile(&pile_b);
	}
	else
		return (1);
}
