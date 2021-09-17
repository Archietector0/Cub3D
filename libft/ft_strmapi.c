/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:18:35 by tbarth            #+#    #+#             */
/*   Updated: 2020/11/20 21:39:59 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*p;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	p = malloc(ft_strlen(s) + 1);
	if (p == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		*(p + i) = f(i, s[i]);
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
