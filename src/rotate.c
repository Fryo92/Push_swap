/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:25:27 by abiddane          #+#    #+#             */
/*   Updated: 2023/02/06 12:15:13 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_pile **pile)
{
	t_pile	*tail;
	t_pile	*tmp;

	tail = pile_last(*pile);
	tmp = *pile;
	*pile = (*pile)->next;
	tmp->next = NULL;
	tail->next = tmp;
}

void	ft_ra(t_pile **pile)
{
	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	ft_rotate(pile);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_pile **pile)
{
	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	ft_rotate(pile);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_pile **pile_a, t_pile **pile_b)
{
	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return ;
	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return ;
	ft_rotate(pile_a);
	ft_rotate(pile_b);
	ft_putstr_fd("rr\n", 1);
}
