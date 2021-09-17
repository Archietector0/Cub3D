/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:49:30 by tbarth            #+#    #+#             */
/*   Updated: 2020/11/22 20:56:35 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i != n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
		{
			return (((unsigned char *)s + i));
		}
		i++;
	}
	return (0);
}
