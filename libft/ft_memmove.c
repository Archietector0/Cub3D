/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:20:35 by tbarth            #+#    #+#             */
/*   Updated: 2020/11/11 18:59:07 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if ((char *)src > (char *)dst)
	{
		while (i != len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
		return (dst);
	}
	else if ((char *)src < (char *)dst)
	{
		while (len != 0)
		{
			*((char *)dst + len - 1) = *((char *)src + len - 1);
			len--;
		}
		return (dst);
	}
	else
	{
		return (dst);
	}
}
