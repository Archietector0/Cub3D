/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_c_part_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:03:43 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/20 17:26:12 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			raycasting_part_1(t_pumpkin *global)
{
	if (global->params.raydirx < 0)
	{
		global->params.stepx = -1;
		global->params.sidedistx = (global->
		pos_x - global->params.mapx) * global->params.deltadistx;
	}
	else
	{
		global->params.stepx = 1;
		global->params.sidedistx = (global->params.mapx + 1.0 -
		global->pos_x) * global->params.deltadistx;
	}
	if (global->params.raydiry < 0)
	{
		global->params.stepy = -1;
		global->params.sidedisty = (global->pos_y - global->
		params.mapy) * global->params.deltadisty;
	}
	else
	{
		global->params.stepy = 1;
		global->params.sidedisty = (global->params.mapy +
		1.0 - global->pos_y) * global->params.deltadisty;
	}
}

void			raycst_p2_pp1(t_pumpkin *global)
{
	if (global->params.side == 0)
		global->params.perpwalldist = (global->params.mapx -
		global->pos_x + (1 - global->params.stepx) / 2) /
		global->params.raydirx;
	else
		global->params.perpwalldist = (global->params.mapy -
		global->pos_y + (1 - global->params.stepy) / 2) /
		global->params.raydiry;
}

void			raycasting_part_2(t_pumpkin *global)
{
	while (global->params.hit == 0)
	{
		if (global->params.sidedistx < global->params.sidedisty)
		{
			global->params.sidedistx += global->params.deltadistx;
			global->params.mapx += global->params.stepx;
			global->params.side = 0;
		}
		else
		{
			global->params.sidedisty += global->params.deltadisty;
			global->params.mapy += global->params.stepy;
			global->params.side = 1;
		}
		if (global->vars->map[global->params.mapy]
		[global->params.mapx] == '1')
			global->params.hit = 1;
	}
	raycst_p2_pp1(global);
}

void			raycasting_part_3(t_pumpkin *global)
{
	global->perp_wall_dist[global->params.x] = global->params.perpwalldist;
	global->params.lineheight = (int)(global->vars->r_y /
	global->params.perpwalldist);
	global->params.drawstart = -global->params.lineheight /
	2 + global->vars->r_y / 2;
	if (global->params.drawstart < 0)
		global->params.drawstart = 0;
	global->params.drawend = global->params.lineheight /
	2 + global->vars->r_y / 2;
	if (global->params.drawend >= global->vars->r_y)
		global->params.drawend = global->vars->r_y - 1;
	if (global->params.side == 0)
		global->params.wallx = global->pos_y + global->
		params.perpwalldist * global->params.raydiry;
	else
		global->params.wallx = global->pos_x + global->
		params.perpwalldist * global->params.raydirx;
	global->params.wallx -= floor((global->params.wallx));
	global->params.texx = (int)(global->params.wallx * (double)(TEXWIDTH));
	if (global->params.side == 0 && global->params.raydirx > 0)
		global->params.texx = TEXWIDTH - global->params.texx - 1;
	if (global->params.side == 1 && global->params.raydiry < 0)
		global->params.texx = TEXWIDTH - global->params.texx - 1;
}

void			raycst_p4_pp1(t_pumpkin *global)
{
	if (global->params.stepx > 0)
	{
		global->params.color = my_mlx_pixel_take(&global->
		texture_east, global->params.texx, global->params.texy);
		my_mlx_pixel_put(&global->img_window, global->params.x,
		global->params.y, global->params.color);
	}
	else if (global->params.stepx < 0)
	{
		global->params.color = my_mlx_pixel_take(&global->
		texture_west, global->params.texx, global->params.texy);
		my_mlx_pixel_put(&global->img_window, global->params.x,
		global->params.y, global->params.color);
	}
}
