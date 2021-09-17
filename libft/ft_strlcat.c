/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:58:38 by tbarth            #+#    #+#             */
/*   Updated: 2020/11/17 12:51:59 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		s;
	int		d;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	s = dst_len;
	d = 0;
	if (dst == '\0' && src == '\0')
		return (0);
	if (dstsize == 0 || dstsize < dst_len)
		return (src_len + dstsize);
	while ((dstsize-- - 1) > dst_len && src[d])
		dst[s++] = src[d++];
	dst[s] = '\0';
	return (src_len + dst_len);
}
