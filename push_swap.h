/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:43 by bhamani           #+#    #+#             */
/*   Updated: 2025/01/21 19:25:09 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

int		ft_strcmp(char *s1, char *s2);
void	tab_free(char **tab);
int		checkargs(char **tab, char **av);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
void	swap_a(t_list **pile_a);
void	swap_b(t_list **pile_b);
void	swap_ab(t_list **pile_b, t_list **pile_a);
void	push_a(t_list **pile_a, t_list **pile_b);
void	push_b(t_list **pile_a, t_list **pile_b);
void	rotate_a(t_list **pile_a);
void	rotate_b(t_list **pile_b);
void	rotate_ab(t_list **pile_a, t_list **pile_b);
void	reverse_rotate_a(t_list **pile_a);
void	reverse_rotate_b(t_list **pile_b);
void	reverse_rotate_ab(t_list **pile_a, t_list **pile_b);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
int		checkocc(char **av);
int		checkchar(char **tab);
int		checkocc2(char **av);
void	three_sort(t_list **pile_a);
void	chunk_sort(t_list **pile_a, t_list **pile_b);
t_list	*allalgo(t_list **pile_a, t_list **pile_b);
void	print_list(t_list *pile_a, t_list **pile_aa);
void	free_list(t_list **list);
void	init_index(t_list *pile_a);
void	index_sort(t_list *pile_a);
int		is_sort(t_list **lst);

#endif