/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiddane <abiddane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:05:25 by abiddane          #+#    #+#             */
/*   Updated: 2023/02/17 13:14:15 by abiddane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pile
{
	struct s_pile	*next;
	int				value;
	int				index;
	int				push;
}				t_pile;

/* check_utils.c */
int				ft_isdigit(char c);
int				ft_issign(char c);
int				ft_strcmp(char *s1, char *s2);

/* check.c */
int				check_arg(int ac, char **av);
int				check_arg_tab(int ac, char **av);

/* index.c */
void			get_index(t_pile *pile_a);

/* init_utils.c */
int				ft_isduplicate2(char **av);
long long int	ft_atoi(const char *nptr);
t_pile			*new_pile(int value);
void			ft_lstadd_back(t_pile **lst, t_pile *new);
void			push_init(t_pile **pile);

/* init.c */
t_pile			*ft_init(int ac, char **av);

/* main.c */
int				ft_sorted(t_pile *pile_a);

/* pile_utils.c */
t_pile			*pile_last(t_pile *pile);
t_pile			*pile_before_last(t_pile *pile);
int				ft_lstsize(t_pile *lst);
int				find_value(t_pile *pile, int value);
int				find_index(t_pile *pile, int index);

/* push.c */
void			ft_pa(t_pile **pile_a, t_pile **pile_b);
void			ft_pb(t_pile **pile_a, t_pile **pile_b);

/* rev_rotate.c */
void			ft_rra(t_pile **pile);
void			ft_rrb(t_pile **pile);
void			ft_rrr(t_pile **pile_a, t_pile **pile_b);

/* rotate.c */
void			ft_ra(t_pile **pile);
void			ft_rb(t_pile **pile);
void			ft_rr(t_pile **pile_a, t_pile **pile_b);

/* sort_little.c */
void			sort_three(t_pile **pile);
void			sort_five(t_pile **pile_a, t_pile **pile_b);

/* sort_utils.c */
int				get_max(t_pile *pile);
int				get_min(t_pile *pile);
int				set_chunk(t_pile **pile_a);
int				chunk_left(t_pile **pile_a, int chunk_size);

/* sort.c */
void			sort_pile(t_pile **pile_a, t_pile **pile_b);

/* split.c */
size_t			ft_strlen(const char *s);
char			**ft_split(char *s, char c);
char			**free_all(char **tab);

/* swap.c */
void			ft_sa(t_pile *pile_a);
void			ft_sb(t_pile *pile_b);
void			ft_ss(t_pile *pile_a, t_pile *pile_b);

/* utils.c */
void			*ft_memset(void *s, int c, size_t n);
void			kill_exe(t_pile **pile_a, t_pile **pile_b, char **tab);
void			free_pile(t_pile **pile);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_tablen(char **tab);

#endif