/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:27:34 by abiddane          #+#    #+#             */
/*   Updated: 2023/02/06 12:40:33 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;

	tmp = (*pile_a)->next;
	(*pile_a)->next = *pile_b;
	*pile_b = *pile_a;
	(*pile_a) = tmp;
}

void	ft_pa(t_pile **pile_a, t_pile **pile_b)
{
	if (*pile_b == NULL)
		return ;
	ft_push(pile_b, pile_a);
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_pile **pile_a, t_pile **pile_b)
{
	if (*pile_a == NULL)
		return ;
	ft_push(pile_a, pile_b);
	ft_putstr_fd("pb\n", 1);
}
