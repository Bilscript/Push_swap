/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructor3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:37:39 by bhamani           #+#    #+#             */
/*   Updated: 2025/01/21 18:37:39 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_b(t_list **pile_b)
{
	t_list	*temp;
	t_list	*last;

	if (!pile_b || !(*pile_b) || !(*pile_b)->next)
		return ;
	last = *pile_b;
	while (last->next)
		last = last->next;
	temp = *pile_b;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *pile_b;
	*pile_b = last;
	write(1, "rrb\n", 4);
}

void	reverse_rotate(t_list **pile)
{
	t_list	*temp;
	t_list	*last;

	if (!pile || !(*pile) || !(*pile)->next)
		return ;
	last = *pile;
	while (last->next)
		last = last->next;
	temp = *pile;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *pile;
	*pile = last;
}

void	reverse_rotate_ab(t_list **pile_a, t_list **pile_b)
{
	reverse_rotate(pile_a);
	reverse_rotate(pile_b);
	write(1, "rrr\n", 4);
}
