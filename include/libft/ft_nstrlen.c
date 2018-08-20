/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 21:53:32 by daalexan          #+#    #+#             */
/*   Updated: 2018/06/06 21:55:06 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nstrlen(const char *str, size_t maxlen)
{
	size_t i;

	i = 0;
	while (*str && i < maxlen)
	{
		i++;
	}
	return (i);
}
