/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_maker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 00:11:03 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/25 01:09:22 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_checker_maker(char *line, int i)
{
	int len;

	len = 0;
	while (ft_isdigit(line[i]))
	{
		if (line[i] != '0')
			i++;
		while (ft_isdigit(line[i]))
		{
			i++;
			len++;
		}
	}
	return (len);
}
