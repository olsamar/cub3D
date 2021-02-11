/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_engine_state.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:26:16 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/08 21:45:54 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENGINE_STATE_H
# define GAME_ENGINE_STATE_H

# include "window.h"
# include "style.h"
# include "map.h"

typedef struct		s_movement
{
	int		rotation_dir;
}					t_movement;

typedef struct		s_texture_info
{
	void		*img;
	int			img_width;
	int			img_height;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}					t_texture_info;


typedef struct		s_game_engine_state
{
	double			dist_to_plane;
	double			pos_x;
	double			pos_y;
	double			direction;
	t_texture_info	tex_info[TEXTURE_COUNT];
	t_window		*window;
	t_style			*style;
	t_map			*map;
	t_movement		move;
}					t_game_engine_state;

#endif