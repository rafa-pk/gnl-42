/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:11:54 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/08 14:57:21 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	buff [BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	while (read(fd, buff, BUFFER_SIZE) > 0 || buff[0] != '\0')
	{
		str = ft_strjoin(str, buff);
		if (!str)
			return (NULL);
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		if (str[ft_strlen(str) - 1] == '\n')
			return (str);
	}
	return (str);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("fd error\n");
	while (get_next_line(fd) != NULL)
		printf("%s\n", get_next_line(fd));
	return (0);
}
