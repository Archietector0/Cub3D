/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:07:33 by tbarth            #+#    #+#             */
/*   Updated: 2020/11/17 16:33:45 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t s;

	s = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dst == 0 || src == 0)
		return (0);
	while (s != dstsize - 1 && src[s] != '\0')
	{
		dst[s] = src[s];
		s++;
	}
	dst[s] = '\0';
	return (ft_strlen(src));
}
