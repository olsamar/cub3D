/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_style.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 11:57:38 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/23 11:57:52 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "../libft/include/libft.h"

#include "parse_map_style.h"
#include "style.h"
#include "window_resolution.h"

// longer way to initialize a structure
	// style.no_texture = NULL;
	// style.so_texture = NULL;
	// style.ea_texture = NULL;
	// style.we_texture = NULL;
	// style.sprite_texture = NULL;
	// style.floor_rgb = 0;
	// style.ceiling_rgb = 0;

int		parse_map_style_descriptor(char *line, int line_num)
{
	t_style 		style;
	unsigned int	floor_color;
	unsigned int	ceiling_color;

	style = (t_style){ 0, 0, 0, 0, 0, 0, 0 };
	if (has_identifier(line, "R "))
	{
		if (!parse_window_resolution(line, line_num))
			return (ERROR);
	}
	else if (has_identifier(line, "NO "))
		style.no_texture = parse_texture_path(line); // don't forget it can return NULL if malloc fails, so check for NULLs afterwards
	else if (has_identifier(line, "SO "))
		style.so_texture = parse_texture_path(line);
	else if (has_identifier(line, "EA "))
		style.ea_texture = parse_texture_path(line);
	else if (has_identifier(line, "WE "))
		style.we_texture = parse_texture_path(line);
	else if (has_identifier(line, "S "))
		style.sprite_texture = parse_texture_path(line);
	else if (has_identifier(line, "C "))
		style.ceiling_rgb = parse_color(line, &ceiling_color);// how to deal with invalid colors?
	else if (has_identifier(line, "F "))
		style.floor_rgb = parse_color(line, &floor_color); // do I check them here or in a separate function?
	free(line);
	line = NULL;
	return (SUCCESS);
}

int		has_identifier(char *line, char *identifier)
{
	int	identifier_len;

	identifier_len = ft_strlen(identifier);
	return (ft_strncmp(line, identifier, identifier_len));
}

char	*parse_texture_path(char *line)
{
	int		i;
	char	*texture_path;

	i = 0;
	while (line[i] != ' ')
	{
		i++;
	}
	texture_path = ft_strtrim(line + i, ' ');
	return (texture_path);
}

int		parse_color(char *line, unsigned int *color)
{
	char	**array;
	int		color_component;
	int		red;
	int		green; // can I use enum here?? how??
	int		blue;

	array = split_color_into_components(line);
	if (array == NULL)
		return (-1);
	color_component = 0;
	if (is_valid_component(array[0], &color_component)
		&& color_component >= 0 && color_component <= 255)
		red = color_component;
	else
		return (-1); // any way not to repeat error message?
	if (is_valid_component(array[1], &color_component)
		&& color_component >= 0 && color_component <= 255)
		green = color_component;
	else
		return (-1);
	if (is_valid_component(array[2], &color_component)
		&& color_component >= 0 && color_component <= 255)
		blue = color_component;
	else
		return (-1);
	free_array_memory(array);
	return (red << 16 | green << 8 | blue);
}

int		is_valid_component(const char *string, int *component)
{
	int		num_chars;
	int		accumulator;
	int		is_valid_component;
	char 	*trimmed_string;

	num_chars = 0;
	is_valid_component = 1;
	trimmed_string = ft_strtrim(string, ' ');
	accumulator = ft_printf_atoi(trimmed_string, &num_chars);
	if (trimmed_string[num_chars] != 0)
	{
		is_valid_component = -1;
	}
	*component = accumulator;
	free(trimmed_string);
	return (is_valid_component);
}

void		free_array_memory(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

static char		**split_color_into_components(char *line)
{
	char	**array;
	int		components_num;
	int		i;

	array = ft_split(line, ',');
	if (array == NULL)
	{
		return (NULL);
	}
	i = 0;
	components_num = 0;
	while (array[i] != NULL)
	{
		components_num++;
		i++;
	}
	if (components_num != 3)
	{
		free_array_memory(array);
		return (NULL);
	}
	return (array);
}