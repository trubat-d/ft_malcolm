/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lord <lord@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:47:47 by lord              #+#    #+#             */
/*   Updated: 2022/10/09 13:54:37 by lord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define UC unsigned char

char	*ft_strnstr(const char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (((UC *)src)[0] == 0)
		return ((char *)dst);
	while (((UC *)dst)[i] && i < n)
	{
		if (((UC *)dst)[i] == ((UC *)src)[0])
		{
			while (((UC *)src)[k] && k + i < n)
			{
				if (((UC *)src)[k] != ((UC *)dst)[i + k])
					break ;
				k++;
			}
			if (k == (size_t)ft_strlen(((char *)src)))
				return (&((char *)dst)[i]);
		}
		i++;
		k = 0;
	}
	return (NULL);
}
