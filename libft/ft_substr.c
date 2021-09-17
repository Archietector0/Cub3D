/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:33:45 by tbarth            #+#    #+#             */
/*   Updated: 2020/11/21 22:41:09 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	start_ptr;

	ptr = (char *)malloc(len + 1);
	if (s == NULL || ptr == NULL)
		return (NULL);
	start_ptr = 0;
	if (start >= ft_strlen(s))
	{
		ptr[0] = '\0';
		return (ptr);
	}
	while (len-- && s[start])
	{
		ptr[start_ptr++] = s[start++];
	}
	ptr[start_ptr] = '\0';
	return (ptr);
}
