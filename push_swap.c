/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:55:54 by bhamani           #+#    #+#             */
/*   Updated: 2025/01/12 18:55:54 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_list **pile_a)
{
	int	a;
	int	b;
	int	c;

	a = (*pile_a)->content;
	b = (*pile_a)->next->content;
	c = (*pile_a)->next->next->content;
	if (a > b && b < c && c > a)
		swap_a(pile_a);
	else if (a > b && b > c && c < a)
	{
		swap_a(pile_a);
		reverse_rotate_a(pile_a);
	}
	else if (a > b && b < c && c < a)
		rotate_a(pile_a);
	else if (a < b && b > c && c > a)
	{
		swap_a(pile_a);
		rotate_a(pile_a);
	}
	else if (a < b && b > c && c < a)
		reverse_rotate_a(pile_a);
}

t_list	*find_smaller(t_list *pile_a)
{
	t_list	*min;

	min = pile_a;
	while (pile_a)
	{
		if (min->content > pile_a->content)
			min = pile_a;
		pile_a = pile_a->next;
	}
	return (min);
}

void	push_smaller(t_list **pile_a, t_list **pile_b)
{
	t_list	*min;
	int		mid;
	int		steps;
	t_list	*current;

	steps = 0;
	current = *pile_a;
	min = find_smaller(*pile_a);
	mid = ft_lstsize(pile_a) / 2;
	while (current != min)
	{
		current = current->next;
		steps++;
	}
	if (steps <= mid)
	{
		while (*pile_a != min)
			rotate_a(pile_a);
	}
	else
	{
		while (*pile_a != min)
			reverse_rotate_a(pile_a);
	}
	push_b(pile_a, pile_b);
}

void	five_sort(t_list **pile_a, t_list **pile_b)
{
	push_smaller(pile_a, pile_b);
	push_smaller(pile_a, pile_b);
	three_sort(pile_a);
	push_a(pile_a, pile_b);
	push_a(pile_a, pile_b);
	if ((*pile_a)->content > (*pile_a)->next->content)
		swap_a(pile_a);
}

t_list	*allalgo(t_list **pile_a, t_list **pile_b)
{
	if (ft_lstsize(pile_a) == 3)
	{
		three_sort(pile_a);
		free_list(pile_a);
		return (*pile_a);
	}
	if (ft_lstsize(pile_a) == 5)
	{
		five_sort(pile_a, pile_b);
		free_list(pile_a);
		return (*pile_a);
	}
	else
	{
		chunk_sort(pile_a, pile_b);
		free_list(pile_a);
	}
	return (*pile_a);
}
