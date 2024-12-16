/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructor2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:24:10 by bhamani           #+#    #+#             */
/*   Updated: 2024/12/16 16:49:23 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **pile_a)
{
	t_list	*temp;
	t_list	*last;

	if (!pile_a || !(*pile_a) || !(*pile_a)->next)
		return ;
	temp = *pile_a;
	*pile_a = (*pile_a)->next;
	last = *pile_a;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **pile_b)
{
	t_list	*temp;
	t_list	*last;

	if (!pile_b || !(*pile_b) || !(*pile_b)->next)
		return ;
	temp = *pile_b;
	*pile_b = (*pile_b)->next;
	last = *pile_b;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	rotate_ab(t_list **pile_a, t_list **pile_b)
{
	t_list	*temp;
	t_list	*last;

	if (pile_a && (*pile_a) && (*pile_a)->next)
	{
		temp = *pile_a;
		*pile_a = (*pile_a)->next;
		last = *pile_a;
		while (last->next)
			last = last->next;
		last->next = temp;
		temp->next = NULL;
	}
	if (pile_b && (*pile_b) && (*pile_b)->next)
	{
		temp = *pile_b;
		*pile_b = (*pile_b)->next;
		last = *pile_b;
		while (last->next)
			last = last->next;
		last->next = temp;
		temp->next = NULL;
	}
	write(1, "rr\n", 3);
}
