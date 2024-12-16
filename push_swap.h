/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:43 by bhamani           #+#    #+#             */
/*   Updated: 2024/12/16 16:20:29 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}					t_list;

void	swap_a(t_list **pile_a);
void	swap_b(t_list **pile_b);
void	swap_ab(t_list **pile_b, t_list **pile_a);
void	push_a(t_list **pile_a, t_list **pile_b);
void	push_b(t_list **pile_a, t_list **pile_b);
void	rotate_a(t_list **pile_a);

#endif