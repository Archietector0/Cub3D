/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:16:32 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/21 15:04:45 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	main_part_4(int argc, char **argv, t_pumpkin *global, t_vars *vars)
{
	(void)argc;
	if (!(argv[2][0] == '-' && argv[2][1] == '-' &&
			argv[2][2] == 's' && argv[2][3] == 'a' &&
			argv[2][4] == 'v' && argv[2][5] == 'e' && argv[2][6] == '\0'))
		error("Error");
	else
	{
		global->mlx = mlx_init();
		global->win = mlx_new_window(global->mlx, vars->r_x,
		vars->r_y, "cube3D");
		global->img_window.img = mlx_new_image(global->mlx, vars->r_x,
		vars->r_y);
		global->img_window.addr = mlx_get_data_addr(global->img_window.img,
		&global->img_window.bits_per_pixel, &global->img_window.line_length,
		&global->img_window.endian);
		convert_to_image(global);
		raycasting(global);
		mlx_put_image_to_window(global->mlx, global->win,
		global->img_window.img, 0, 0);
		screenshot(global);
	}
}

void	main_part_3(int argc, char **argv, t_pumpkin *global, t_vars *vars)
{
	(void)argc;
	(void)argv;
	global->win = mlx_new_window(global->mlx, vars->r_x, vars->r_y, "cube3D");
	global->img_window.img = mlx_new_image(global->mlx, vars->r_x, vars->r_y);
	global->img_window.addr = mlx_get_data_addr(global->img_window.img,
	&global->img_window.bits_per_pixel, &global->img_window.line_length,
	&global->img_window.endian);
	convert_to_image(global);
	raycasting(global);
	mlx_put_image_to_window(global->mlx, global->win,
	global->img_window.img, 0, 0);
	mlx_hook(global->win, 2, 1L << 0, key_hook, global);
	mlx_hook(global->win, 17, 1L << 0, destroy_win, global);
	mlx_loop(global->mlx);
}

void	check_valide_symbol(char **map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0' &&
			map[i][j] != ' ' && map[i][j] != 'N' && map[i][j] != 'W'
			&& map[i][j] != 'E' && map[i][j] != 'S' &&
			map[i][j] != 'N' && map[i][j] != '2')
				error("Undefine symbol in map!\n");
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_after_map(char *line)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != '0' &&
		line[i] != ' ' && line[i] != 'N' && line[i] != 'W'
		&& line[i] != 'E' && line[i] != 'S' &&
		line[i] != 'N' && line[i] != '2')
			error("Undefine symbol in line!\n");
		i++;
	}
}

void	pars_pp5(t_vars *vars, char **argv)
{
	char		*line;
	int			fd;
	int			is_map;

	line = NULL;
	is_map = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Not open file\n");
	init_vars(vars);
	vars->string = ft_strdup("");
	while (get_next_line(fd, &line))
		pars_pp1(vars, is_map, line);
	free(line);
	vars->map = ft_split(vars->string, '*');
	check_valide_symbol(vars->map);
}
