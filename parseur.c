/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:52:41 by bhamani           #+#    #+#             */
/*   Updated: 2024/12/23 17:35:39 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkchar(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		i = 0;
		if (tab[j][0] == '-' || tab[j][0] == '+')
			i++;
		while (tab[j][i])
		{
			if (tab[j][i] < '0' || tab[j][i] > '9')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	checkocc(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (!ft_strcmp(av[i], av[j]))
			{
				printf("FFFFFFFF\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	checksagrm(char **av)
{
	int		i;
	int		j;
	char	**tab;

	tab = ft_split(av[1], ' ');
	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (!ft_strcmp(tab[i], tab[j]))
			{
				printf("FFFFFFFF\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	checkargs(char **tab, char **av)
{
	if (!checkchar(tab))
		return (0);
	if (!checkocc(av) || !checksagrm(av))
		return (0);
	return (1);
}


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
		if (!checkargs(tab, av))
		{
			tab_free(tab);
			write (1, "Error\n", 6);
			return (0);
		}
		j = 0;
		while (tab[j])
		{
			ft_lstadd_back(&pile_a, ft_lstnew(ft_atoi(tab[j])));
			j++;
		}
		i++;
		tab_free(tab);
	}
	return (pile_a);
}

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
	t_list	*temp;

	pile_a = parseur(argc, argv);
	temp = pile_a;
	while (temp)
	{
		printf ("%d\n", temp->content);
		temp = temp->next;
	}
	free_list(&pile_a);
}
