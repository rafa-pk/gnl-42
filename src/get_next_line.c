/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:11:54 by raica-ba          #+#    #+#             */
/*   Updated: 2025/02/24 12:36:26 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str;
	static char	buf [BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;

	while (read(fd, buf, BUFFER_SIZE) || buf[0])
	{
		str = ft_strjoin(buf, str);
		if (!str)
			return (NULL);
		buffer_cleaner(buf);
		if (str[ft_strlen(str) - 1] == '\n')
			return (str);
	}
	return (str);
}
