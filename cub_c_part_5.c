/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_c_part_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:12:20 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/20 17:28:54 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		key_hook_part_1(int keycode, t_pumpkin *global)
{
	float		move_speed;

	move_speed = 0.1;
	if (keycode == 53)
		exit(1);
	if (keycode == 13)
	{
		if (global->vars->map[(int)(global->pos_y + global->
		dir_y * move_speed)][(int)(global->pos_x)] == '0')
			global->pos_y += global->dir_y * move_speed;
		if (global->vars->map[(int)(global->pos_y)][(int)
		(global->pos_x + global->dir_x * move_speed)] == '0')
			global->pos_x += global->dir_x * move_speed;
	}
	if (keycode == 1)
	{
		if (global->vars->map[(int)(global->pos_y - global->
		dir_y * move_speed)][(int)(global->pos_x)] == '0')
			global->pos_y -= global->dir_y * move_speed;
		if (global->vars->map[(int)(global->pos_y)][(int)
		(global->pos_x - global->dir_x * move_speed)] == '0')
			global->pos_x -= global->dir_x * move_speed;
	}
}

void		key_hook_part_2(int keycode, t_pumpkin *global)
{
	float		move_speed;

	move_speed = 0.1;
	if (keycode == 0)
	{
		if (global->vars->map[(int)(global->pos_y)][(int)
		(global->pos_x + global->dir_y * move_speed)] == '0')
			global->pos_x += global->dir_y * move_speed;
		if (global->vars->map[(int)(global->pos_y - global->
		dir_x * move_speed)][(int)(global->pos_x)] == '0')
			global->pos_y -= global->dir_x * move_speed;
	}
	if (keycode == 2)
	{
		if (global->vars->map[(int)(global->pos_y)][(int)
		(global->pos_x - global->dir_y * move_speed)] == '0')
			global->pos_x -= global->dir_y * move_speed;
		if (global->vars->map[(int)(global->pos_y + global->
		dir_x * move_speed)][(int)(global->pos_x)] == '0')
			global->pos_y += global->dir_x * move_speed;
	}
}

void		key_hook_part_3(int keycode, t_pumpkin *global)
{
	float		rotation_speed;
	double		olddirx;
	double		oldplanex;

	rotation_speed = 0.1;
	olddirx = global->dir_x;
	oldplanex = global->plane_x;
	if (keycode == 123)
	{
		global->dir_x = global->dir_x * cos(-rotation_speed) -
		global->dir_y * sin(-rotation_speed);
		global->dir_y = olddirx * sin(-rotation_speed) + global->
		dir_y * cos(-rotation_speed);
		global->plane_x = global->plane_x * cos(-rotation_speed) -
		global->plane_y * sin(-rotation_speed);
		global->plane_y = oldplanex * sin(-rotation_speed) +
		global->plane_y * cos(-rotation_speed);
	}
}

int			key_hook_part_4(int keycode, t_pumpkin *global)
{
	(void)keycode;
	mlx_destroy_image(global->mlx, global->img_window.img);
	global->img_window.img = mlx_new_image(global->mlx,
	global->vars->r_x, global->vars->r_y);
	global->img_window.addr = mlx_get_data_addr(global->
	img_window.img, &global->img_window.bits_per_pixel,
	&global->img_window.line_length, &global->img_window.endian);
	raycasting(global);
	mlx_put_image_to_window(global->mlx, global->win, global->
	img_window.img, 0, 0);
	return (1);
}

int			key_hook(int keycode, t_pumpkin *global)
{
	float		move_speed;
	float		rotation_speed;
	double		olddirx;
	double		oldplanex;

	move_speed = 0.1;
	rotation_speed = 0.1;
	olddirx = global->dir_x;
	oldplanex = global->plane_x;
	key_hook_part_1(keycode, global);
	key_hook_part_2(keycode, global);
	key_hook_part_3(keycode, global);
	if (keycode == 124)
	{
		global->dir_x = global->dir_x * cos(rotation_speed) -
		global->dir_y * sin(rotation_speed);
		global->dir_y = olddirx * sin(rotation_speed) +
		global->dir_y * cos(rotation_speed);
		global->plane_x = global->plane_x * cos(rotation_speed) -
		global->plane_y * sin(rotation_speed);
		global->plane_y = oldplanex * sin(rotation_speed) +
		global->plane_y * cos(rotation_speed);
	}
	key_hook_part_4(keycode, global);
	return (1);
}
