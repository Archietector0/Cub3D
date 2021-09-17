/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:25:47 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/25 00:42:14 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		color_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int		destroy_win(t_pumpkin *global)
{
	(void)global;
	exit(1);
	return (1);
}

void	error(char *error)
{
	write(1, error, ft_strlen(error));
	exit(1);
}

void	main_part_2(char **argv, t_pumpkin *global, t_vars *vars)
{
	pars(vars, argv);
	global->vars = vars;
	global->special_sym = 0;
	pos_player(global);
	quantity_sprite(global);
	malloc_array(global);
	search_sprite(global);
	eye_player(global);
	global->screen_x = vars->r_x;
	global->screen_y = vars->r_y;
	global->vars->map[(int)(global->pos_y)][(int)(global->pos_x)] = '0';
	if ((global->vars->cr > 255 || global->vars->cr < 0) ||
		(global->vars->cg > 255 || global->vars->cg < 0) ||
		(global->vars->cb > 255 || global->vars->cb < 0))
		error("Error Color!\n");
	if ((global->vars->fr > 255 || global->vars->fr < 0) ||
		(global->vars->fg > 255 || global->vars->fg < 0) ||
		(global->vars->fb > 255 || global->vars->fb < 0))
		error("Error Color!\n");
	if (global->vars->r_x < 1 || global->vars->r_y < 1)
		error("Not valide resolution!\n");
	global->mlx = mlx_init();
}

int		main(int argc, char **argv)
{
	t_pumpkin	global;
	t_vars		vars;
	int			x;
	int			y;

	main_part_2(argv, &global, &vars);
	mlx_get_screen_size(global.mlx, &x, &y);
	if (global.vars->r_x > x)
	{
		global.vars->r_x = x;
		global.screen_x = x;
	}
	if (global.vars->r_y > y)
	{
		global.vars->r_y = y;
		global.screen_y = y;
	}
	if (argc == 2)
		main_part_3(argc, argv, &global, &vars);
	else if (argc == 3)
		main_part_4(argc, argv, &global, &vars);
}
