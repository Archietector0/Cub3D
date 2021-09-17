/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:32:10 by tbarth            #+#    #+#             */
/*   Updated: 2020/11/21 17:57:13 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1[0] == '\0' && s2[0] == '\0')
		return (0);
	while (i != n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (*((char *)s1 + i) != *((char *)s2 + i))
		{
			return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
		}
		i++;
	}
	return (0);
}
