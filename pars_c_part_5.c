/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_c_part_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:17:51 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/20 15:41:37 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_find_c(t_vars *vars, char *line)
{
	vars->i = 0;
	vars->flag = 0;
	ft_find_c_pp1(vars, line);
	ft_find_c_pp2(vars, line);
	ft_find_c_pp3(vars, line);
	if (ft_isdigit(line[vars->i]))
	{
		vars->cb = ft_atoi(&line[vars->i]);
		while (ft_isdigit(line[vars->i]))
			vars->i++;
		while (line[vars->i] != '\0')
		{
			if (line[vars->i] != '\t' || line[vars->i] != ' ')
				vars->flag++;
			vars->i++;
		}
	}
	if (vars->flag != 0 || vars->cr == -1 || vars->cg == -1 || vars->cb == -1)
	{
		error("Non Valid map");
		return ;
	}
}

char	*ft_strdup_n(const char *s1)
{
	size_t	i;
	size_t	p;
	char	*ptr;
	int		start;

	p = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	ptr = malloc(i + 2);
	start = 0;
	while (s1[start])
	{
		ptr[start] = s1[start];
		start++;
	}
	ptr[start] = '*';
	ptr[start + 1] = '\0';
	return (ptr);
}

void	ft_find_map(t_vars *vars, char *line)
{
	int		i;
	char	*leaks;

	i = 0;
	if (vars->error != 8)
		error("Error");
	line = ft_strdup_n(line);
	leaks = vars->string;
	vars->string = ft_strjoin(vars->string, line);
	free(line);
	free(leaks);
}

int		check_valide(char symbol)
{
	if (symbol == '0' || symbol == 'W' ||
		symbol == 'S' || symbol == 'E' ||
		symbol == 'N' || symbol == '2' ||
		symbol == '1')
		return (1);
	return (0);
}

void	ft_valid_map(t_vars *vars, char **argv, int i, int j)
{
	(void)argv;
	if (ft_strlen(vars->map[i - 1]) < j)
		error("Error");
	if (ft_strlen(vars->map[i + 1]) < j)
		error("Error");
	if (check_valide(vars->map[i - 1][j - 1]) == 0)
		error("Error");
	if (check_valide(vars->map[i - 1][j]) == 0)
		error("Error");
	if (check_valide(vars->map[i - 1][j + 1]) == 0)
		error("Error");
	if (check_valide(vars->map[i][j - 1]) == 0)
		error("Error");
	if (check_valide(vars->map[i][j + 1]) == 0)
		error("Error");
	if (check_valide(vars->map[i + 1][j - 1]) == 0)
		error("Error");
	if (check_valide(vars->map[i + 1][j]) == 0)
		error("Error");
	if (check_valide(vars->map[i + 1][j + 1]) == 0)
		error("Error");
}
