/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_c_part_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:11:37 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/17 18:01:39 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_find_so_pp1(t_vars *vars, char *line, int i, int flag)
{
	if (line[i] == '.' && line[i + 1] == '/')
	{
		line += i;
		vars->so = ft_strdup(line);
	}
	else
		flag++;
	if (flag != 0)
	{
		error("Non Valid map");
		return ;
	}
}

void	ft_find_so(t_vars *vars, char *line)
{
	int				i;
	static int		flag;

	i = 0;
	flag = 0;
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i] == 'S' && line[i + 1] == 'O')
	{
		vars->error++;
		i += 2;
	}
	else
		flag++;
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	ft_find_so_pp1(vars, line, i, flag);
}

void	ft_find_we_pp1(t_vars *vars, char *line, int i, int flag)
{
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i] == '.' && line[i + 1] == '/')
	{
		line += i;
		vars->we = ft_strdup(line);
	}
	else
		flag++;
	if (flag != 0)
	{
		error("Non Valid map");
		return ;
	}
}

void	ft_find_we(t_vars *vars, char *line)
{
	int				i;
	static int		flag;

	i = 0;
	flag = 0;
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i] == 'W' && line[i + 1] == 'E')
	{
		vars->error++;
		i += 2;
	}
	else
		flag++;
	ft_find_we_pp1(vars, line, i, flag);
}

void	ft_find_ea_pp1(t_vars *vars, char *line, int i, int flag)
{
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i] == '.' && line[i + 1] == '/')
	{
		line += i;
		vars->ea = ft_strdup(line);
	}
	else
		flag++;
	if (flag != 0)
	{
		error("Non Valid map");
		return ;
	}
}
