/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_c_part_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:15:34 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/20 17:27:00 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			raycst_p4_pp2(t_pumpkin *global)
{
	if (global->params.stepy > 0)
	{
		global->params.color = my_mlx_pixel_take(&global->
		texture_south, global->params.texx,
		global->params.texy);
		my_mlx_pixel_put(&global->img_window, global->params.x,
		global->params.y, global->params.color);
	}
	else if (global->params.stepy < 0)
	{
		global->params.color = my_mlx_pixel_take(&global->
		texture_north, global->params.texx,
		global->params.texy);
		my_mlx_pixel_put(&global->img_window, global->params.x,
		global->params.y, global->params.color);
	}
}

void			raycasting_part_4(t_pumpkin *global)
{
	while (global->params.y < global->vars->r_y)
	{
		if (global->params.y < global->params.drawstart)
			my_mlx_pixel_put(&global->img_window,
			global->params.x, global->params.y, color_rgb(global->vars->
			cr, global->vars->cg, global->vars->cb));
		if (global->params.y > global->params.drawstart + 3 &&
		global->params.y < global->params.drawend - 3)
		{
			global->params.texy = (int)global->
			params.texpos & (TEXHEIGHT - 1);
			global->params.texpos += global->params.step;
			if (global->params.side == 0)
				raycst_p4_pp1(global);
			else if (global->params.side == 1)
				raycst_p4_pp2(global);
		}
		if (global->params.y > global->params.drawend)
			my_mlx_pixel_put(&global->img_window, global->
			params.x, global->params.y, color_rgb(global->vars->fr,
			global->vars->fg, global->vars->fb));
		global->params.y++;
	}
}

void			raycasting_part_5(t_pumpkin *global)
{
	global->params.spritex = global->
	sprite_x[global->params.i] - global->pos_x;
	global->params.spritey = global->
	sprite_y[global->params.i] - global->pos_y;
	global->params.invdet = 1.0 / (global->plane_x * global->
	dir_y - global->dir_x * global->plane_y);
	global->params.transformx = global->params.invdet * (global->
	dir_y * global->params.spritex - global->dir_x *
	global->params.spritey);
	global->params.transformy = global->params.invdet *
	(-global->plane_y * global->params.spritex + global->
	plane_x * global->params.spritey);
	global->params.spritescreenx = (int)((global->
	screen_x / 2) * (1 + global->params.transformx /
	global->params.transformy));
	global->params.spriteheight = abs((int)(global->
	screen_y / (global->params.transformy)));
	global->params.drawstarty = -global->params.spriteheight /
	2 + global->vars->r_y / 2;
}

void			raycasting_part_6(t_pumpkin *global)
{
	if (global->params.drawstarty < 0)
		global->params.drawstarty = 0;
	global->params.drawendy = global->params.spriteheight /
	2 + global->vars->r_y / 2;
	if (global->params.drawendy >= global->vars->r_y)
		global->params.drawendy = global->vars->r_y - 1;
	global->params.spritewidth = abs((int)(global->vars->r_y /
	(global->params.transformy)));
	global->params.drawstartx = -global->params.spritewidth /
	2 + global->params.spritescreenx;
	if (global->params.drawstartx < 0)
		global->params.drawstartx = 0;
	global->params.drawendx = global->params.spritewidth /
	2 + global->params.spritescreenx;
	global->params.stripe = global->params.drawstartx;
	if (global->params.drawendx >= global->vars->r_x)
		global->params.drawendx = global->vars->r_x - 1;
}

void			raycst_p7_pp1(t_pumpkin *global)
{
	global->params.d = (global->params.y) * 256 -
	global->vars->r_y * 128 + global->params.spriteheight * 128;
	global->params.texy = ((global->params.d * TEXHEIGHT) /
	global->params.spriteheight) / 256;
	global->params.color = my_mlx_pixel_take(&global->sprite,
	global->params.texx, global->params.texy);
	if (global->params.color > 0)
		my_mlx_pixel_put(&global->img_window, global->
		params.stripe, global->params.y, global->
		params.color);
	global->params.y++;
}
