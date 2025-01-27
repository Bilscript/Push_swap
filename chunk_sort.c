/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:28:15 by bhamani           #+#    #+#             */
/*   Updated: 2025/01/21 18:28:15 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 4)
		return (1);
	i = 2;
	while (i * i < nb)
		i++;
	if (i * i > nb)
	{
		if ((i * i - nb) < ((i - 1) * (i - 1) + (-nb)))
			return (i);
	}
	return (i - 1);
}

void	find_bigger(t_list **pile_b)
{
	t_list	*highest;
	t_list	*current;
	int		mid;

	if (!pile_b || !(*pile_b))
		return ;
	highest = (*pile_b);
	init_index(highest);
	current = (*pile_b);
	mid = ft_lstsize(pile_b) / 2;
	if (ft_lstsize(pile_b) % 2 != 0)
		mid++;
	while (current)
	{
		if (current->content > highest->content)
			highest = current;
		current = current->next;
	}
	while (*pile_b != highest)
	{
		if (highest->index > mid)
			reverse_rotate_b(pile_b);
		else
			rotate_b(pile_b);
	}
}

int	choose_rotate(t_list **pile_a, int start, int end)
{
	int		mid;
	int		i;
	t_list	*temp;

	mid = ft_lstsize(pile_a) / 2;
	i = 0;
	temp = *pile_a;
	while (temp)
	{
		if (temp->index >= start && temp->index <= end)
			return (i > mid);
		i++;
		temp = temp->next;
	}
	return (0);
}

void	push_chunk_b(t_list **pile_a, t_list **pile_b, int start, int end)
{
	t_list	*temp;
	int		elem_in_chunk;
	int		count_in_chunk;

	temp = *pile_a;
	count_in_chunk = 0;
	elem_in_chunk = 0;
	while (temp)
	{
		if (temp->index >= start && temp->index <= end)
			elem_in_chunk++;
		temp = temp->next;
	}
	while (count_in_chunk < elem_in_chunk)
	{
		if ((*pile_a)->index >= start && (*pile_a)->index <= end)
		{
			push_b(pile_a, pile_b);
			count_in_chunk++;
		}
		else if (choose_rotate(pile_a, start, end))
			reverse_rotate_a(pile_a);
		else
			rotate_a(pile_a);
	}
}

void	chunk_sort(t_list **pile_a, t_list **pile_b)
{
	int		start;
	int		end;
	int		total_size;
	int		size_chunk;

	total_size = ft_lstsize(pile_a);
	size_chunk = ft_sqrt(ft_lstsize(pile_a)) * 1.35;
	start = 0;
	end = size_chunk - 1;
	index_sort(*pile_a);
	while (start < total_size)
	{
		push_chunk_b (pile_a, pile_b, start, end);
		start += size_chunk;
		end += size_chunk;
		if (end >= total_size)
			end = total_size - 1;
	}
	while (*pile_b != NULL)
	{
		find_bigger(pile_b);
		push_a(pile_a, pile_b);
	}
}
