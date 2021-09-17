/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_c_part_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:15:19 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/20 17:26:53 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			raycasting_part_7(t_pumpkin *global)
{
	while (global->params.stripe < global->params.drawendx)
	{
		global->params.texx = (int)(256 * (global->
		params.stripe - (-global->params.spritewidth /
		2 + global->params.spritescreenx)) * TEXWIDTH /
		global->params.spritewidth) / 256;
		global->params.y = global->params.drawstarty;
		if (global->params.transformy > 0 && global->
		params.stripe > 0 && global->params.stripe <
		global->vars->r_x && global->params.transformy <
		global->perp_wall_dist[global->params.stripe])
			while (global->params.y < global->params.drawendy)
				raycst_p7_pp1(global);
		global->params.stripe++;
	}
}

void			raycasting_part_8(t_pumpkin *global)
{
	global->params.camerax = 2 * global->params.x /
	(double)global->vars->r_x - 1;
	global->params.raydirx = global->dir_x + global->
	plane_x * global->params.camerax;
	global->params.raydiry = global->dir_y + global->
	plane_y * global->params.camerax;
	global->params.mapx = (int)(global->pos_x);
	global->params.mapy = (int)(global->pos_y);
	global->params.deltadistx = sqrt(1 + (global->
	params.raydiry * global->params.raydiry) /
	(global->params.raydirx * global->params.raydirx));
	global->params.deltadisty = sqrt(1 + (global->
	params.raydirx * global->params.raydirx) /
	(global->params.raydiry * global->params.raydiry));
	global->params.hit = 0;
	raycasting_part_1(global);
	raycasting_part_2(global);
	raycasting_part_3(global);
	global->params.step = 1.0 * TEXHEIGHT / global->params.lineheight;
	global->params.texpos = (global->params.drawstart -
	global->vars->r_y / 2 + global->params.lineheight / 2) *
	global->params.step;
	global->params.y = 0;
	raycasting_part_4(global);
}

void			raycasting(t_pumpkin *global)
{
	global->params.x = 0;
	while (global->params.x < global->vars->r_x)
	{
		raycasting_part_8(global);
		global->params.x++;
	}
	threatment_distance(global);
	bubble_sort_sprite(global);
	global->params.i = 0;
	while (global->params.i < global->quantity_sprite)
	{
		raycasting_part_5(global);
		raycasting_part_6(global);
		raycasting_part_7(global);
		global->params.i++;
	}
}

void			convert_to_image_2(t_pumpkin *global)
{
	global->texture_south.img = mlx_xpm_file_to_image(global->mlx,
	global->vars->so, &global->texture_south.width,
	&global->texture_south.height);
	if (global->texture_south.img == NULL)
		error("\nerror!");
	global->texture_south.addr = mlx_get_data_addr(global->texture_south.img,
	&global->texture_south.bits_per_pixel,
	&global->texture_south.line_length, &global->texture_south.endian);
	global->texture_east.img = mlx_xpm_file_to_image(global->mlx,
	global->vars->ea, &global->texture_east.width,
	&global->texture_east.height);
}

void			malloc_array(t_pumpkin *global)
{
	global->sprite_x = malloc(sizeof(float) * global->quantity_sprite);
	global->sprite_y = malloc(sizeof(float) * global->quantity_sprite);
	global->distance = malloc(sizeof(float) * global->quantity_sprite);
	global->perp_wall_dist = malloc(sizeof(float) * global->vars->r_x);
}
