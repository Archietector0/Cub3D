/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_c_part_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:18:00 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/17 18:00:47 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int		my_mlx_pixel_take(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

void				bubble_position_sprite(t_pumpkin *global, int i, int j)
{
	float tmp;
	float position;

	tmp = 0;
	position = 0;
	tmp = global->distance[j];
	global->distance[j] = global->distance[i];
	global->distance[i] = tmp;
	position = global->sprite_x[i];
	global->sprite_x[i] = global->sprite_x[j];
	global->sprite_x[j] = position;
	position = global->sprite_y[i];
	global->sprite_y[i] = global->sprite_y[j];
	global->sprite_y[j] = position;
}

void				bubble_sort_sprite(t_pumpkin *global)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < global->quantity_sprite)
	{
		while (j < global->quantity_sprite)
		{
			if (global->distance[i]
					> global->distance[j])
			{
				bubble_position_sprite(global, i, j);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void				threatment_distance(t_pumpkin *global)
{
	int i;

	i = 0;
	while (i < global->quantity_sprite)
	{
		global->distance[i] = ((global->pos_x
			- global->sprite_x[i])
			* (global->pos_x - global->sprite_x[i])
			+ (global->pos_y - global->sprite_y[i])
			* (global->pos_y - global->sprite_y[i]));
		i++;
	}
}
