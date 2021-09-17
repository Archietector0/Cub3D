/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_c_part_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:07:30 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/25 00:09:16 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_vars(t_vars *vars)
{
	vars->r_x = -1;
	vars->r_y = -1;
	vars->no = NULL;
	vars->so = NULL;
	vars->we = NULL;
	vars->ea = NULL;
	vars->s = NULL;
	vars->fr = -1;
	vars->fg = -1;
	vars->fb = -1;
	vars->cr = -1;
	vars->cg = -1;
	vars->cb = -1;
	vars->error = 0;
	vars->map = NULL;
}

void	ft_find_r_pp1(t_vars *vars, char *line, int i, int flag)
{
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (ft_checker_maker(line, i) > 4)
		vars->r_y = 9999;
	else
		vars->r_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) == 1)
		i++;
	while (line[i] != '\0')
	{
		if (line[i] != '\t' || line[i] != ' ')
			flag++;
		i++;
	}
	if (flag != 0)
	{
		vars->r_x = 0;
		vars->r_y = 0;
		error("Non Valid map");
		return ;
	}
}

void	ft_find_r(t_vars *vars, char *line)
{
	int				i;
	static int		flag;

	i = 0;
	flag = 0;
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i++] == 'R')
		vars->error++;
	else
		flag++;
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]))
	{
		if (ft_checker_maker(line, i) > 4)
			vars->r_x = 9999;
		else
			vars->r_x = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]) == 1)
			i++;
	}
	else
		flag++;
	ft_find_r_pp1(vars, line, i, flag);
}

void	ft_find_no_pp1(t_vars *vars, char *line, int i, int flag)
{
	if (line[i] == '.' && line[i + 1] == '/')
	{
		line += i;
		vars->no = ft_strdup(line);
	}
	else
		flag++;
	if (flag != 0)
	{
		error("Non Valid map");
		return ;
	}
}

void	ft_find_no(t_vars *vars, char *line)
{
	int				i;
	static int		flag;

	i = 0;
	flag = 0;
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		vars->error++;
		i += 2;
	}
	else
		flag++;
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	ft_find_no_pp1(vars, line, i, flag);
}
