/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:18:33 by tbarth            #+#    #+#             */
/*   Updated: 2020/11/13 19:33:40 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	p;
	void	*ptr;

	p = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	ptr = malloc(i + 1);
	if (ptr == NULL)
		return (NULL);
	while (ptr + p <= ptr + i)
	{
		*((char *)ptr + p) = *((char *)s1 + p);
		p++;
	}
	return (ptr);
}
