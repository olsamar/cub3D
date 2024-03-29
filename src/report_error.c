/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   report_error.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 12:47:47 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/11 23:32:30 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "libft.h"

#include "report_error.h"

int	report_error_with_line(int line_num, char *message)
{
	char	*line_num_to_alpha;
	char	*err;

	err = "\e[31m Error\n \e[0m";
	write(1, err, ft_strlen(err));
	line_num_to_alpha = ft_itoa(line_num);
	write(1, "Line ", 5);
	write(1, line_num_to_alpha, ft_strlen(line_num_to_alpha));
	write(1, ": ", 2);
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	free(line_num_to_alpha);
	return (ERROR);
}

int	report_error(char *message)
{
	char	*err;

	err = "\e[31m Error\n \e[0m";
	write(1, err, ft_strlen(err));
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	return (ERROR);
}
