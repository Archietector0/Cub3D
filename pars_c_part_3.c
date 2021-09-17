/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_c_part_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:13:46 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/17 18:01:42 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_find_ea(t_vars *vars, char *line)
{
	int				i;
	static int		flag;

	i = 0;
	flag = 0;
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i] == 'E' && line[i + 1] == 'A')
	{
		vars->error++;
		i += 2;
	}
	else
		flag++;
	ft_find_ea_pp1(vars, line, i, flag);
}

void	ft_find_s_pp1(t_vars *vars, char *line, int i, int flag)
{
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i] == '.' && line[i + 1] == '/')
	{
		line += i;
		vars->s = ft_strdup(line);
	}
	else
		flag++;
	if (flag != 0)
	{
		error("Non Valid map");
		return ;
	}
}

void	ft_find_s(t_vars *vars, char *line)
{
	int				i;
	static int		flag;

	i = 0;
	flag = 0;
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i] == 'S')
	{
		vars->error++;
		i++;
	}
	else
		flag++;
	ft_find_s_pp1(vars, line, i, flag);
}

void	ft_find_f_pp1(t_vars *vars, char *line)
{
	while (line[vars->i] == '\t' || line[vars->i] == ' ')
		vars->i++;
	if (line[vars->i] == 'F')
	{
		vars->error++;
		vars->i++;
	}
	else
		vars->flag++;
	while (line[vars->i] == '\t' || line[vars->i] == ' ')
		vars->i++;
}

void	ft_find_f_pp2(t_vars *vars, char *line)
{
	if (ft_isdigit(line[vars->i]))
	{
		vars->fr = ft_atoi(&line[vars->i]);
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
