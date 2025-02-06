/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lord <lord@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:45:35 by lord              #+#    #+#             */
/*   Updated: 2022/10/09 13:56:05 by lord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	dst_size;

	dst_size = ft_strlen(dst);
	if (dst_size >= n)
	{
		return (ft_strlen((char *)src) + n);
	}
	n = n - dst_size;
	i = 0;
	while (i < n - 1 && src[i])
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (ft_strlen((char *)src) + dst_size);
}
