/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:10:22 by tbarth            #+#    #+#             */
/*   Updated: 2020/11/17 14:22:01 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		p;
	char	*ptr;

	if (s1 == '\0' || s2 == '\0')
		return (NULL);
	i = ft_strlen(s1);
	p = ft_strlen(s2);
	ptr = malloc(i + p + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	p = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = *((char *)&(s1[i]));
		i++;
	}
	*(ptr + i) = '\0';
	while (s2[p] != '\0')
		ptr[i++] = *((char *)&(s2[p++]));
	*(ptr + i) = '\0';
	return (ptr);
}
