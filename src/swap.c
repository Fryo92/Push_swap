/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:58:34 by abiddane          #+#    #+#             */
/*   Updated: 2023/02/06 13:08:52 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_pile *pile)
{
	int	tmp;

	tmp = pile->value;
	pile->value = pile->next->value;
	pile->next->value = tmp;
	tmp = pile->index;
	pile->index = pile->next->index;
	pile->next->index = tmp;
	tmp = pile->push;
	pile->push = pile->next->push;
	pile->next->push = tmp;
}

void	ft_sa(t_pile *pile_a)
{
	if (pile_a == NULL || pile_a->next == NULL)
		return ;
	ft_swap(pile_a);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_pile *pile_b)
{
	if (pile_b == NULL || pile_b->next == NULL)
		return ;
	ft_swap(pile_b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a == NULL || pile_a->next == NULL)
		return ;
	if (pile_b == NULL || pile_b->next == NULL)
		return ;
	ft_swap(pile_a);
	ft_swap(pile_b);
	ft_putstr_fd("ss\n", 1);
}
