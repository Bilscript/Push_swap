/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:34:44 by bhamani           #+#    #+#             */
/*   Updated: 2025/01/21 18:34:44 by bhamani          ###   ########.fr       */
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
		if (tab[j][i] < '0' || tab[j][i] > '9')
		{
			return (0);
		}
		while (tab[j][i])
		{
			if (tab[j][i] < '0' || tab[j][i] > '9')
			{
				return (0);
			}
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
				write (1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	checkocc2(char **av)
{
	int		i;
	int		j;
	char	**tab;

	tab = ft_split(av[1], ' ');
	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (!ft_strcmp(tab[i], tab[j]))
			{
				tab_free(tab);
				write (1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	tab_free(tab);
	return (1);
}
