/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:31:03 by bhamani           #+#    #+#             */
/*   Updated: 2025/01/21 18:31:03 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_index(t_list *pile_a)
{
	int	i;

	i = 0;
	while (pile_a)
	{
		pile_a->index = i;
		i++;
		pile_a = pile_a->next;
	}
}

void	index_sort(t_list *pile_a)
{
	t_list	*current;
	t_list	*temp;
	int		i;

	current = pile_a;
	while (current)
	{
		i = 0;
		temp = pile_a;
		while (temp)
		{
			if (temp->content < current->content)
				i++;
			temp = temp->next;
		}
		current->index = i;
		current = current->next;
	}
}
