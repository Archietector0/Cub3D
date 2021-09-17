/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:19:57 by tbarth            #+#    #+#             */
/*   Updated: 2020/11/22 20:19:43 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s1, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			i++;
		else
		{
			count++;
			while (s1[i] != c && (s1[i] == c || s1[i] != '\0'))
				i++;
		}
	}
	return (count);
}

static int	ft_count_letter(char const *s1, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] == c)
	{
		i++;
	}
	while (s1[i] != c && s1[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

static void	*ft_duckhead_free(char **ptr, int i)
{
	while (i >= 0)
		free(ptr[--i]);
	free(ptr);
	return (NULL);
}

char		**ft_split(char const *s1, char c)
{
	char	**ptr;
	int		arr[3];

	arr[0] = 0;
	arr[1] = 0;
	if (s1 == NULL)
		return (NULL);
	arr[2] = ft_count_word(s1, c);
	if (!(ptr = malloc(sizeof(char *) * (arr[2] + 1))))
		return (NULL);
	while (arr[0] < arr[2])
	{
		while (*s1 == c)
			s1++;
		if (!(ptr[arr[0]] = malloc((ft_count_letter(s1, c) + 1))))
			return (ft_duckhead_free(ptr, arr[0]));
		while (*s1 != c && *s1)
			ptr[arr[0]][arr[1]++] = *(s1++);
		ptr[arr[0]][arr[1]] = '\0';
		arr[1] = 0;
		arr[0]++;
	}
	ptr[arr[0]] = NULL;
	return (ptr);
}
