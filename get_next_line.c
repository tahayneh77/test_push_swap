/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*str_append_char(char *str, char c, int len)
{
	char	*new_str;
	int		i;

	new_str = (char *)malloc(sizeof(char) * (len + 2));
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buf;
	int		bytes;
	int		len;

	if (fd < 0)
		return (NULL);
	line = NULL;
	len = 0;
	while (1)
	{
		bytes = read(fd, &buf, 1);
		if (bytes <= 0)
			break ;
		line = str_append_char(line, buf, len++);
		if (!line || buf == '\n')
			break ;
	}
	if (bytes < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
