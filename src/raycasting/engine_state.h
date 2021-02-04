/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   engine_state.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:26:16 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/04 17:39:42 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_STATE_H
# define ENGINE_STATE_H

# define TILE_SIZE 1

typedef struct		s_engine_state
{
	int			FOV;
	double		pos_x;
	double		pos_y;
}					t_engine_state;


#endif