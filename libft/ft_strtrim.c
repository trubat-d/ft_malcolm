/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:50:17 by lord              #+#    #+#             */
/*   Updated: 2022/10/10 16:44:41 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	isinset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	trimmed_len(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] && isinset(str[i], charset))
		i++;
	cnt = i;
	i = ft_strlen(str)-1;
	while (str[i] && isinset(str[i], charset))
	{
		cnt++;
		i--;
	}
	return (ft_strlen(str) - cnt);
}

static int	isall_char(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!isinset(str[i], set))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_check(void)
{
	char	*res;

	res = malloc(1 * sizeof(char));
	res[0] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	int		i;

	if (!isall_char((char *)s1, (char *)set))
		return (ft_check());
	res = malloc(trimmed_len((char *)s1, (char *)set) * sizeof(char) + 1);
	if (!res)
		return (NULL);
	end = ft_strlen((char *)s1) - 1;
	while (end >= 0 && isinset(s1[end], (char *)set))
		end--;
	start = 0;
	while (s1[start] && isinset(s1[start], (char *)set))
		start++;
	i = 0;
	while (start < end +1)
	{
		res[i] = s1[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
