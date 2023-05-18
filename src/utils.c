/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:56:39 by abiddane          #+#    #+#             */
/*   Updated: 2023/02/06 12:14:25 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_tablen(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = s;
	while (i < n)
	{
		dest[i] = c;
		i++;
	}
	return (s);
}

void	free_pile(t_pile **pile)
{
	t_pile	*tmp;

	if (!pile || !(*pile))
		return ;
	while (*pile)
	{
		tmp = (*pile)->next;
		free(*pile);
		*pile = tmp;
	}
}

void	kill_exe(t_pile **pile_a, t_pile **pile_b, char	**tab)
{
	if (tab != NULL)
		free_all(tab);
	if (pile_a == NULL || *pile_a != NULL)
		free_pile(pile_a);
	if (pile_b == NULL || *pile_b != NULL)
		free_pile(pile_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
