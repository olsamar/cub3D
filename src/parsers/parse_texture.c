/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_texture.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 17:00:29 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/30 17:08:26 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

#include "parse_texture.h"
#include "parsing_utils.h"
#include "report_error.h"

static t_texture_identifier		g_texture_identifier[] =
{
	{"NO ", TEXTURE_NO},
	{"SO ", TEXTURE_SO},
	{"EA ", TEXTURE_EA},
	{"WE ", TEXTURE_WE},
	{"S ", TEXTURE_SPRITE}
};

int		parse_walls_textures(char *line, int line_num, t_style *style)
{
	int		identifier_len;
	int		i;

	identifier_len = 0;
	i = 0;
	while (i < TEXTURE_COUNT)
	{
		if (has_identifier(line, g_texture_identifier[i].identifier, &identifier_len))
		{
			if (style->textures[g_texture_identifier[i].index] != NULL)
				return (report_error_with_line(line_num, "Repeating texture element."));
			style->textures[g_texture_identifier[i].index] = ft_strtrim(line + identifier_len, " ");
			return (SUCCESS);
		}
		i++;
	}
	return (NOT_FOUND);
}