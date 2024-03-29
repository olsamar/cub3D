/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 17:33:01 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/08 23:11:26 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "resolution.h"

typedef struct s_window
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_window;

int	start_window(t_window *window, t_resolution *resolution, int screenshot);

#endif