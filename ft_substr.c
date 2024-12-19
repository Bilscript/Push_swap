/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:50:26 by bhamani           #+#    #+#             */
/*   Updated: 2024/10/30 22:50:26 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	checklen;

	i = 0;
	if (!s)
		return (NULL);
	checklen = ft_strlen((char *)s);
	if (start >= checklen)
		return (ft_strdup(""));
	if (len > checklen - start)
		len = checklen - start;
	sub = (char *)malloc((len + 1) * sizeof (char));
	if (!sub)
		return (NULL);
	while (len)
	{
		sub[i] = s[start + i];
		i++;
		len--;
	}
	sub[i] = '\0';
	return (sub);
}
