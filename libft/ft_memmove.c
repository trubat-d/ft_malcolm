/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:42:19 by lord              #+#    #+#             */
/*   Updated: 2022/10/10 18:23:56 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include<stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (n == 0)
		return (dest);
	if (dest == 0 && src == 0)
		return (0);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	unsigned char *dest = malloc(9);
	dest[8] = '\0';
	int i = 1;
	while(i < 8)
	{
		dest[i] = "12345678"[i];
		i++;
	}
	ft_memmove(dest, &dest[2], 8);
	printf("%s\n", dest);
	return 0;
}
*/