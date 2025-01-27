/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:41:44 by bhamani           #+#    #+#             */
/*   Updated: 2025/01/21 18:47:10 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **pile_a)
{
	int	temp;

	if (!pile_a || !(*pile_a))
		return ;
	temp = (*pile_a)->content;
	(*pile_a)->content = (*pile_a)->next->content;
	(*pile_a)->next->content = temp;
	write (1, "sa\n", 3);
}

void	swap_b(t_list **pile_b)
{
	int	temp;

	if (!pile_b || !(*pile_b))
		return ;
	temp = (*pile_b)->content;
	(*pile_b)->content = (*pile_b)->next->content;
	(*pile_b)->next->content = temp;
	write(1, "sb\n", 3);
}

void	swap_ab(t_list **pile_b, t_list **pile_a)
{
	t_list	*temp;

	if (pile_a && (*pile_a) && (*pile_a)->next)
	{
		temp = (*pile_a)->next;
		(*pile_a)->next = temp->next;
		temp->next = *pile_a;
		*pile_a = temp;
	}
	if (pile_b && (*pile_b) && (*pile_b)->next)
	{
		temp = (*pile_b)->next;
		(*pile_b)->next = temp->next;
		temp->next = *pile_b;
		*pile_b = temp;
	}
	write(1, "ss\n", 3);
}

void	push_a(t_list **pile_a, t_list **pile_b)
{
	t_list	*temp;

	if (!pile_b || !(*pile_b))
		return ;
	temp = *pile_b;
	*pile_b = (*pile_b)->next;
	temp->next = *pile_a;
	*pile_a = temp;
	write(1, "pa\n", 3);
}

void	push_b(t_list **pile_a, t_list **pile_b)
{
	t_list	*temp;

	if (!pile_a || !(*pile_a))
		return ;
	temp = *pile_a;
	*pile_a = (*pile_a)->next;
	temp->next = *pile_b;
	*pile_b = temp;
	write(1, "pb\n", 3);
}
