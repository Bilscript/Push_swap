/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:44:16 by bhamani           #+#    #+#             */
/*   Updated: 2024/10/14 19:44:16 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*dup;

	i = 0;
	size = ft_strlen(s);
	dup = (char *)malloc(sizeof (char) * (size + 1));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i1;
	unsigned int	i2;

	i1 = 0;
	i2 = 0;
	if (s1[i1] == '+')
		i1++;
	if (s2[i2] == '+')
		i2++;
	while (s1[i1] == s2[i2] && (s1[i1] != '\0' || s2[i2] != '\0'))
	{
		i1++;
		i2++;
	}
	return (s1[i1] - s2[i2]);
}
