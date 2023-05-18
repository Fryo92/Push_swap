/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:45:20 by abiddane          #+#    #+#             */
/*   Updated: 2023/02/06 12:10:43 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_pile **pile)
{
	t_pile	*last;
	t_pile	*before;
	t_pile	*tmp;

	last = pile_last(*pile);
	before = pile_before_last(*pile);
	tmp = *pile;
	*pile = last;
	last->next = tmp;
	before->next = NULL;
}

void	ft_rra(t_pile **pile)
{
	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	ft_rev_rotate(pile);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_pile **pile)
{
	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	ft_rev_rotate(pile);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_pile **pile_a, t_pile **pile_b)
{
	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return ;
	ft_rev_rotate(pile_a);
	ft_rev_rotate(pile_b);
	ft_putstr_fd("rrr\n", 1);
}
