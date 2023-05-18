/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:33:09 by abiddane          #+#    #+#             */
/*   Updated: 2023/02/08 13:40:16 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**tab_init(char *str)
{
	char	**tab;

	tab = ft_split(str, ' ');
	if (!check_arg_tab(ft_tablen(tab), tab))
	{
		free_all(tab);
		kill_exe(NULL, NULL, NULL);
	}
	return (tab);
}

t_pile	*pile_init(int ac, char **av)
{
	t_pile			*pile_a;
	long long int	value;
	int				i;

	pile_a = NULL;
	i = 1;
	while (i < ac)
	{
		value = ft_atoi(av[i]);
		if (i == 1 && (value > 2147483647 || value < -2147483648))
			kill_exe(NULL, NULL, NULL);
		if (i > 1 && (value > 2147483647 || value < -2147483648))
			kill_exe(&pile_a, NULL, NULL);
		if (i == 1)
			pile_a = new_pile((int)value);
		else
			ft_lstadd_back(&pile_a, new_pile((int)value));
		i++;
	}
	return (pile_a);
}

t_pile	*pile_init_tab(int ac, char **av)
{
	t_pile			*pile_a;
	long long int	value;
	int				i;

	pile_a = NULL;
	i = 0;
	while (i < ac)
	{
		value = ft_atoi(av[i]);
		if (i == 0 && (value > 2147483647 || value < -2147483648))
			kill_exe(NULL, NULL, av);
		if (i > 0 && (value > 2147483647 || value < -2147483648))
			kill_exe(&pile_a, NULL, av);
		if (i == 0)
			pile_a = new_pile((int)value);
		else
			ft_lstadd_back(&pile_a, new_pile((int)value));
		i++;
	}
	return (pile_a);
}

t_pile	*ft_init(int ac, char **av)
{
	t_pile	*pile_a;
	char	**tab;

	if (ac == 2)
	{
		tab = tab_init(av[1]);
		pile_a = pile_init_tab(ft_tablen(tab), tab);
		free_all(tab);
	}
	else
	{
		if (!check_arg(ac, av))
			kill_exe(NULL, NULL, NULL);
		pile_a = pile_init(ac, av);
	}
	get_index(pile_a);
	return (pile_a);
}
