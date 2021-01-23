/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_color.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 17:07:48 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/23 17:41:45 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parse_color.h"
#include "style.h"
#include "parsing_utils.h"
#include "report_error.h"

int		parse_floor_ceiling_colors(char *line, int line_num)
{
	int					identifier_len;
	t_style				style;
	unsigned int		color;
	int					is_valid_color;

	identifier_len = 0;
	style.floor_rgb = 0;
	style.ceiling_rgb = 0;
	color = 0;
	if (has_identifier(line, "C ", &identifier_len))
	{
		is_valid_color = parse_color(line + identifier_len, &color);
		if (is_valid_color < 0)
			style.ceiling_rgb = color;
		else
			return (report_error(line_num, "Invalid celing color."));
	}
	else if (has_identifier(line, "F ", &identifier_len))
	{
		is_valid_color = parse_color(line + identifier_len, &color);
		if (is_valid_color < 0)
			style.floor_rgb = color;
		else
			return (report_error(line_num, "Invalid floor color."));
	}
	return (SUCCESS);
}

int		parse_color(char *line, unsigned int *color)
{
	char	**array;
	int		num_components;
	int		red;
	int		green; // can I use enum here?? how??
	int		blue;

	num_components = 3;
	array = split_into_components(line, ',', num_components);
	if (array == NULL)
		return (-1); // find the way to return ERROR (0) here
	if (!is_valid_color(array, &red, &green, &blue))
		return (-1);
	free_array_memory(array);
	*color = red << 16 | green << 8 | blue;
	return (SUCCESS);
}


int		is_valid_color(char **array, int *red, int *green, int *blue)
{
	int		color_component;

	color_component = 0;
	if (is_valid_component(array[0], &color_component)
		&& color_component >= 0 && color_component <= 255)
		*red = color_component;
	else
		return (-1); // any way not to repeat error message?
	if (is_valid_component(array[1], &color_component)
		&& color_component >= 0 && color_component <= 255)
		*green = color_component;
	else
		return (-1);
	if (is_valid_component(array[2], &color_component)
		&& color_component >= 0 && color_component <= 255)
		*blue = color_component;
	else
		return (-1);
	return (SUCCESS);
}
