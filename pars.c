/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:15:15 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/21 15:04:36 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pars_pp1(t_vars *vars, int is_map, char *line)
{
	if (ft_strnstr(line, "R", ft_strlen(line)) && is_map == 0)
		ft_find_r(vars, line);
	else if (ft_strnstr(line, "NO", ft_strlen(line)) && is_map == 0)
		ft_find_no(vars, line);
	else if (ft_strnstr(line, "SO", ft_strlen(line)) && is_map == 0)
		ft_find_so(vars, line);
	else if (ft_strnstr(line, "WE", ft_strlen(line)) && is_map == 0)
		ft_find_we(vars, line);
	else if (ft_strnstr(line, "EA", ft_strlen(line)) && is_map == 0)
		ft_find_ea(vars, line);
	else if (ft_strnstr(line, "F", ft_strlen(line)) && is_map == 0)
		ft_find_f(vars, line);
	else if (ft_strnstr(line, "C", ft_strlen(line)) && is_map == 0)
		ft_find_c(vars, line);
	else if (ft_strnstr(line, "1", ft_strlen(line)))
	{
		ft_find_map(vars, line);
		is_map = 1;
		vars->is_map = 1;
	}
	else if (ft_strnstr(line, "S", ft_strlen(line)) && is_map == 0)
		ft_find_s(vars, line);
	if (vars->is_map == 1)
		check_after_map(line);
	free(line);
}

void	pars_pp2(t_vars *vars, char **argv, int i, int j)
{
	(void)argv;
	if (i == 0)
	{
		while (vars->map[i][j] != '\0')
		{
			if (vars->map[i][j] == ' ' || vars->map[i][j] == '1')
				j++;
			else
				error("Error");
		}
	}
	j = 0;
	if (vars->map[i + 1] == '\0')
	{
		while (vars->map[i][j] != '\0')
		{
			if (vars->map[i][j] == ' ' || vars->map[i][j] == '1')
				j++;
			else
				error("Error");
		}
	}
}

void	pars_pp3(t_vars *vars, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (vars->map[i] != NULL)
	{
		while (vars->map[i][j] != '\0')
		{
			if (vars->map[i][j] == '0' || vars->map[i][j] == 'W' ||
			vars->map[i][j] == 'S' || vars->map[i][j] == 'E' ||
			vars->map[i][j] == 'N' || vars->map[i][j] == '2')
			{
				ft_valid_map(vars, argv, i, j);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	pars_pp4(t_vars *vars, char **argv)
{
	int i;

	pars_pp3(vars, argv);
	free(vars->string);
	i = 0;
	while (vars->map[i])
		i++;
}

void	pars(t_vars *vars, char **argv)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	pars_pp5(vars, argv);
	while (vars->map[i] != '\0')
	{
		pars_pp2(vars, argv, i, j);
		i++;
	}
	i = 0;
	j = 0;
	while (vars->map[i] != NULL)
	{
		while (vars->map[i][j] != '\0')
		{
			if (vars->map[i][j] == '\n')
				error("ERROR\n");
			j++;
		}
		j = 0;
		i++;
	}
	pars_pp4(vars, argv);
}
