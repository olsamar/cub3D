/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   style.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 21:51:42 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/22 17:40:38 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLE_H
# define STYLE_H

typedef struct		s_style
{
    char			*no_texture;
    char			*so_texture;
    char			*ea_texture;
    char			*we_texture;
    char			*sprite_texture;
    unsigned int	floor_rgb; // do they have to be unsigned ints or do I make them ints to be able to check the error
    unsigned int	ceiling_rgb;
}					t_style;

#endif