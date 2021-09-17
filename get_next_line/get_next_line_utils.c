/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:42:59 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/20 15:45:45 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup1(const char *s1)
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

char	*ft_strchr1(const	char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&(s[i]));
		i++;
	}
	if (c == '\0')
		return ((char *)&(s[i]));
	return (0);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	int		i;
	int		p;
	char	*ptr;
	char	*free_ptr;

	if (s1 == '\0' || s2 == '\0')
		return (NULL);
	free_ptr = s1;
	ptr = malloc(ft_strlen1(s1) + ft_strlen1(s2) + 1);
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
	free(free_ptr);
	return (ptr);
}
