/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:28:17 by daalexan          #+#    #+#             */
/*   Updated: 2017/11/01 14:41:49 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *arr1;
	char *arr2;

	if (n == 0 || dest == src)
		return (dest);
	arr1 = (char*)dest;
	arr2 = (char*)src;
	while (--n != 0)
	{
		*arr1++ = *arr2++;
	}
	*arr1 = *arr2;
	return (dest);
}
