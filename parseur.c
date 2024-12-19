/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:52:41 by bhamani           #+#    #+#             */
/*   Updated: 2024/12/19 14:30:32 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parseur(int ac, char **av)
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
		while (tab[j])
		{
			ft_lstadd_back(&pile_a, ft_lstnew(ft_atoi(tab[j])));
			j++;
		}
		i++;
	}
	return (pile_a);
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;
	t_list	*temp;

	pile_a = parseur(argc, argv);
	temp = pile_a;
	while (temp)
	{
		printf ("%d\n", temp->content);
		temp = temp->next;
	}
}
