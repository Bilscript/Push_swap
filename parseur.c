/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:52:41 by bhamani           #+#    #+#             */
/*   Updated: 2025/01/22 14:01:39 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **list)
{
	t_list	*current;
	t_list	*next;

	if (!list || !(*list))
		return ;
	current = *list;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*list = NULL;
}

int	checkargs(char **tab, char **av)
{
	int		j;
	long	nb;

	nb = 0;
	j = 0;
	if (!checkchar(tab))
	{
		write (1, "Error\n", 6);
		return (0);
	}
	if (!checkocc(av) || !checkocc2(av))
		return (0);
	while (tab[j])
	{
		nb = ft_atoi(tab[j]);
		if (nb == LONG_MAX)
		{
			write (1, "Error\n", 6);
			return (0);
		}
		j++;
	}
	return (1);
}

t_list	*parseur(char **av)
{
	t_list	*pile_a;
	char	**tab;
	int		i;
	int		j;

	pile_a = NULL;
	i = 1;
	while (av[i])
	{
		j = 0;
		tab = ft_split(av[i], ' ');
		if (!checkargs(tab, av))
		{
			tab_free(tab);
			free_list(&pile_a);
			return (0);
		}
		while (tab[j])
			ft_lstadd_back(&pile_a, ft_lstnew(ft_atoi(tab[j++])));
		i++;
		tab_free(tab);
	}
	return (pile_a);
}

void	tab_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;

	pile_a = parseur(argv);
	if (is_sort(&pile_a))
		return (0);
	pile_b = NULL;
	if (argc == 1 || !pile_a)
		return (0);
	init_index(pile_a);
	allalgo(&pile_a, &pile_b);
}
