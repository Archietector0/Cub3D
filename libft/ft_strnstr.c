/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:51:26 by tbarth            #+#    #+#             */
/*   Updated: 2020/11/25 17:37:31 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			j = 1;
			while (little[j] && big[i + j] == little[j] && (i + j) < len)
				j++;
			if (!little[j])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
