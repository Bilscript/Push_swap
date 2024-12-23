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
/*
int ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (0);
		i++;
	}
	return (1);
}
*/
int ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

    i = 0;
	if (to_find[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}


