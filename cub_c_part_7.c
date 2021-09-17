/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_c_part_7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:55:31 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/25 00:08:19 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			convert_to_image_1(t_pumpkin *global)
{
	global->texture_north.img = mlx_xpm_file_to_image(global->mlx,
	global->vars->no, &global->texture_north.width,
	&global->texture_north.height);
	if (global->texture_north.img == NULL)
		error("\nerror!");
	global->texture_north.addr = mlx_get_data_addr(global->texture_north.img,
	&global->texture_north.bits_per_pixel, &global->texture_north.line_length,
	&global->texture_north.endian);
}

void			convert_to_image(t_pumpkin *global)
{
	convert_to_image_1(global);
	convert_to_image_2(global);
	if (global->texture_east.img == NULL)
		error("\nerror!");
	global->texture_east.addr = mlx_get_data_addr(global->texture_east.img,
	&global->texture_east.bits_per_pixel,
	&global->texture_east.line_length, &global->texture_east.endian);
	global->texture_west.img = mlx_xpm_file_to_image(global->mlx,
	global->vars->we, &global->texture_west.width,
	&global->texture_west.height);
	if (global->texture_west.img == NULL)
		error("\nerror!");
	global->texture_west.addr = mlx_get_data_addr(global->texture_west.img,
	&global->texture_west.bits_per_pixel,
	&global->texture_west.line_length, &global->texture_west.endian);
	global->sprite.img = mlx_xpm_file_to_image(global->mlx,
	global->vars->s, &global->sprite.width, &global->sprite.height);
	if (global->sprite.img == NULL)
		error("\nerror!");
	global->sprite.addr = mlx_get_data_addr(global->sprite.img, &global->
	sprite.bits_per_pixel, &global->sprite.line_length, &global->sprite.endian);
}

void			pos_player_pp1(t_pumpkin *global, int i, int j)
{
	global->special_sym++;
	global->pos_x = j + 0.5;
	global->pos_y = i + 0.5;
	global->symbol_player = global->vars->map[i][j];
	global->vars->map[i][j] = '0';
}

void			pos_player(t_pumpkin *global)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (global->vars->map[i] != NULL)
	{
		while (global->vars->map[i][j] != '\0')
		{
			if (global->vars->map[i][j] == 'N' ||
			global->vars->map[i][j] == 'W' ||
			global->vars->map[i][j] == 'E' || global->vars->map[i][j] == 'S')
				pos_player_pp1(global, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	if (global->special_sym != 1)
		error("Error : not player");
}

void			quantity_sprite(t_pumpkin *global)
{
	int i;
	int j;
	int quantity_sprite;

	i = 0;
	j = 0;
	quantity_sprite = 0;
	while (global->vars->map[i] != NULL)
	{
		while (global->vars->map[i][j] != '\0')
		{
			if (global->vars->map[i][j] == '2')
				quantity_sprite++;
			j++;
		}
		j = 0;
		i++;
	}
	global->quantity_sprite = quantity_sprite;
}
