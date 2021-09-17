/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_c_part_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:15:45 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/17 18:01:46 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_find_f_pp3(t_vars *vars, char *line)
{
	if (ft_isdigit(line[vars->i]))
	{
		vars->fg = ft_atoi(&line[vars->i]);
		while (ft_isdigit(line[vars->i]))
			vars->i++;
		while (line[vars->i] == '\t' || line[vars->i] == ' ')
			vars->i++;
		if (line[vars->i] == ',')
			vars->i++;
		else
			vars->flag++;
		while (line[vars->i] == '\t' || line[vars->i] == ' ')
			vars->i++;
	}
}

void	ft_find_f(t_vars *vars, char *line)
{
	vars->i = 0;
	vars->flag = 0;
	ft_find_f_pp1(vars, line);
	ft_find_f_pp2(vars, line);
	ft_find_f_pp3(vars, line);
	if (ft_isdigit(line[vars->i]))
	{
		vars->fb = ft_atoi(&line[vars->i]);
		while (ft_isdigit(line[vars->i]))
			vars->i++;
		while (line[vars->i] != '\0')
		{
			if (line[vars->i] != '\t' || line[vars->i] != ' ')
				vars->flag++;
			vars->i++;
		}
	}
	if (vars->flag != 0 || vars->fr == -1 || vars->fg == -1 || vars->fb == -1)
	{
		error("Non Valid map");
		return ;
	}
}

void	ft_find_c_pp1(t_vars *vars, char *line)
{
	while (line[vars->i] == '\t' || line[vars->i] == ' ')
		vars->i++;
	if (line[vars->i] == 'C')
	{
		vars->error++;
		vars->i++;
	}
	else
		vars->flag++;
	while (line[vars->i] == '\t' || line[vars->i] == ' ')
		vars->i++;
}

void	ft_find_c_pp2(t_vars *vars, char *line)
{
	if (ft_isdigit(line[vars->i]))
	{
		vars->cr = ft_atoi(&line[vars->i]);
		while (ft_isdigit(line[vars->i]))
			vars->i++;
		while (line[vars->i] == '\t' || line[vars->i] == ' ')
			vars->i++;
		if (line[vars->i] == ',')
			vars->i++;
		else
			vars->flag++;
		while (line[vars->i] == '\t' || line[vars->i] == ' ')
			vars->i++;
	}
}

void	ft_find_c_pp3(t_vars *vars, char *line)
{
	if (ft_isdigit(line[vars->i]))
	{
		vars->cg = ft_atoi(&line[vars->i]);
		while (ft_isdigit(line[vars->i]))
			vars->i++;
		while (line[vars->i] == '\t' || line[vars->i] == ' ')
			vars->i++;
		if (line[vars->i] == ',')
			vars->i++;
		else
			vars->flag++;
		while (line[vars->i] == '\t' || line[vars->i] == ' ')
			vars->i++;
	}
}
