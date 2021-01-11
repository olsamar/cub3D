/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 16:27:42 by osamara       #+#    #+#                 */
/*   Updated: 2020/12/14 15:17:00 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s != c)
		{
			s++;
		}
		else
		{
			return ((char*)s);
		}
	}
	if (c == '\0')
	{
		return ((char*)s);
	}
	return (NULL);
}