/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_c_part_8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:01:49 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/17 18:01:13 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			search_sprite(t_pumpkin *global)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (global->vars->map[i] != NULL)
	{
		while (global->vars->map[i][j] != '\0')
		{
			if (global->vars->map[i][j] == '2')
			{
				global->sprite_x[count] = j + 0.5f;
				global->sprite_y[count] = i + 0.5f;
				count++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void			filling_file_screenshot(int fd, t_pumpkin *global)
{
	int	i;
	int	j;
	int	color;

	i = global->vars->r_y;
	while (--i >= 0)
	{
		j = -1;
		while (++j < global->vars->r_x)
		{
			color = *(int*)(global->img_window.addr +
			(i * global->img_window.line_length + j *
			(global->img_window.bits_per_pixel / 8)));
			write(fd, &color, 4);
		}
	}
}

void			continue_screenshot(t_pumpkin *global, int fd)
{
	int		size_screen;
	int		pos_pixel_data;
	int		zero;
	short	plane;

	plane = 1;
	zero = 0;
	pos_pixel_data = 54;
	size_screen = global->vars->r_x
	* global->vars->r_y * 4 + 54;
	write(fd, "BM", 2);
	write(fd, &size_screen, 4);
	write(fd, &zero, 4);
	write(fd, &pos_pixel_data, 4);
	pos_pixel_data = 40;
	write(fd, &pos_pixel_data, 4);
	write(fd, &global->vars->r_x, 4);
	write(fd, &global->vars->r_y, 4);
	write(fd, &plane, 2);
	plane = 32;
	write(fd, &plane, 2);
}

void			screenshot(t_pumpkin *global)
{
	int fd;
	int size_screen;
	int zero;
	int size;

	fd = open("screen.bmp", O_CREAT | O_RDWR, 0666);
	size_screen = global->vars->r_x
		* global->vars->r_y * 4 + 54;
	zero = 0;
	size = global->vars->r_x
		* global->vars->r_y;
	if (fd < 0)
		write(1, "Error!\n", 7);
	continue_screenshot(global, fd);
	write(fd, &zero, 4);
	write(fd, &size, 4);
	size_screen = 1000;
	write(fd, &size_screen, 4);
	write(fd, &size_screen, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
	filling_file_screenshot(fd, global);
	close(fd);
}

void			eye_player(t_pumpkin *global)
{
	if (global->symbol_player == 'N')
	{
		global->dir_y = -1;
		global->plane_x = 0.66;
	}
	if (global->symbol_player == 'S')
	{
		global->dir_y = 1;
		global->plane_x = -0.66;
	}
	if (global->symbol_player == 'W')
	{
		global->dir_x = -1;
		global->plane_y = -0.66;
	}
	if (global->symbol_player == 'E')
	{
		global->dir_x = 1;
		global->plane_y = 0.66;
	}
}
