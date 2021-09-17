/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:41:05 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/25 00:59:28 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include "minilibx_mms/mlx.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# define MAPWIDTH 24
# define MAPHEIGHT 24
# define TEXWIDTH 64
# define TEXHEIGHT 64

typedef struct		s_raycast
{
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			wallx;
	int				texx;
	double			step;
	double			texpos;
	unsigned int	color;
	int				y;
	int				x;
	int				i;
	int				d;
	int				texy;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				stripe;
}					t_raycast;

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	float			distance;
}					t_data;

typedef struct		s_vars
{
	int				r_x;
	int				r_y;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				fr;
	int				fg;
	int				fb;
	int				cr;
	int				cg;
	int				cb;
	char			**map;
	char			*string;
	int				error;
	int				i;
	int				flag;
	int				is_map;
}					t_vars;

typedef struct		s_pumpkin
{
	void			*mlx;
	void			*win;
	t_data			img_window;
	t_data			texture_north;
	t_data			texture_south;
	t_data			texture_east;
	t_data			texture_west;
	t_data			sprite;
	float			pos_x;
	float			pos_y;
	float			dir_x;
	float			dir_y;
	float			plane_x;
	float			plane_y;
	int				screen_x;
	int				screen_y;
	float			*sprite_x;
	float			*sprite_y;
	float			*distance;
	int				quantity_sprite;
	int				special_sym;
	char			symbol_player;
	t_vars			*vars;
	t_raycast		params;
	float			*perp_wall_dist;
}					t_pumpkin;

void				pars(t_vars *vars, char **argv);
int					check_valide(char symbol);
void				ft_valid_map(t_vars *vars, char **argv,
					int i, int j);
void				ft_find_map(t_vars *vars, char *line);
char				*ft_strdup_n(const char *s1);
void				ft_find_c(t_vars *vars, char *line);
void				ft_find_c_pp1(t_vars *vars, char *line);
void				ft_find_c_pp2(t_vars *vars, char *line);
void				ft_find_c_pp3(t_vars *vars, char *line);
void				ft_find_f(t_vars *vars, char *line);
void				ft_find_f_pp1(t_vars *vars, char *line);
void				ft_find_f_pp2(t_vars *vars, char *line);
void				ft_find_f_pp3(t_vars *vars, char *line);
void				ft_find_s(t_vars *vars, char *line);
void				ft_find_s_pp1(t_vars *vars, char *line,
					int i, int flag);
void				ft_find_ea(t_vars *vars, char *line);
void				ft_find_ea_pp1(t_vars *vars, char *line,
					int i, int flag);
void				ft_find_we(t_vars *vars, char *line);
void				ft_find_we_pp1(t_vars *vars, char *line,
					int i, int flag);
void				ft_find_so(t_vars *vars, char *line);
void				ft_find_so_pp1(t_vars *vars, char *line,
					int i, int flag);
void				ft_find_no(t_vars *vars, char *line);
void				ft_find_no_pp1(t_vars *vars, char *line,
					int i, int flag);
void				ft_find_r(t_vars *vars, char *line);
void				ft_find_r_pp1(t_vars *vars, char *line,
					int i, int flag);
void				init_vars(t_vars *vars);
void				pars_part_1(t_vars *vars, char *line);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int		my_mlx_pixel_take(t_data *data, int x, int y);
void				bubble_position_sprite(t_pumpkin *global, int i, int j);
void				bubble_sort_sprite(t_pumpkin *global);
void				threatment_distance(t_pumpkin *global);
void				convert_to_image_1(t_pumpkin *global);
void				convert_to_image_2(t_pumpkin *global);
void				convert_to_image(t_pumpkin *global);
void				pos_player(t_pumpkin *global);
void				quantity_sprite(t_pumpkin *global);
void				malloc_array(t_pumpkin *global);
void				search_sprite(t_pumpkin *global);
void				filling_file_screenshot(int fd, t_pumpkin *global);
void				continue_screenshot(t_pumpkin *global, int fd);
void				screenshot(t_pumpkin *global);
void				eye_player(t_pumpkin *global);
void				error(char *error);
void				raycasting(t_pumpkin *global);
int					color_rgb(int r, int g, int b);
void				raycasting_part_1(t_pumpkin *global);
void				raycst_p2_pp1(t_pumpkin *global);
void				raycasting_part_2(t_pumpkin *global);
void				raycasting_part_3(t_pumpkin *global);
void				raycst_p4_pp1(t_pumpkin *global);
void				raycst_p4_pp2(t_pumpkin *global);
void				raycasting_part_4(t_pumpkin *global);
void				raycasting_part_5(t_pumpkin *global);
void				raycasting_part_6(t_pumpkin *global);
void				raycst_p7_pp1(t_pumpkin *global);
void				raycasting_part_7(t_pumpkin *global);
void				raycasting_part_8(t_pumpkin *global);
void				key_hook_part_1(int keycode, t_pumpkin *global);
void				key_hook_part_2(int keycode, t_pumpkin *global);
void				key_hook_part_3(int keycode, t_pumpkin *global);
int					key_hook_part_4(int keycode, t_pumpkin *global);
int					key_hook(int keycode, t_pumpkin *global);
void				main_part_2(char **argv, t_pumpkin *global, t_vars *vars);
void				main_part_3(int argc, char **argv, t_pumpkin
					*global, t_vars *vars);
void				main_part_4(int argc, char **argv, t_pumpkin
					*global, t_vars *vars);
int					destroy_win(t_pumpkin *global);
void				pars_pp1(t_vars *vars, int is_map, char *line);
void				pars_pp5(t_vars *vars, char **argv);
void				check_after_map(char *line);
int					ft_checker_maker(char *line, int i);
#endif
