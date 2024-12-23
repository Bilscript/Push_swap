/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:43 by bhamani           #+#    #+#             */
/*   Updated: 2024/12/23 17:30:18 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

int		ft_strcmp(char *s1, char *s2);
void	tab_free(char **tab);
int		checkargs(char **tab, char **av);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
void	swap_a(t_list **pile_a);
void	swap_b(t_list **pile_b);
void	swap_ab(t_list **pile_b, t_list **pile_a);
void	push_a(t_list **pile_a, t_list **pile_b);
void	push_b(t_list **pile_a, t_list **pile_b);
void	rotate_a(t_list **pile_a);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);

#endif