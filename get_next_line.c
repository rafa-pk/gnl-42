/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:11:54 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/09 13:45:38 by raica-ba         ###   ########.fr       */
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
	while (buff[0] != '\0' || read(fd, buff, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buff);
		if (!str)
			return (NULL);
		buff_cleaner(buff);
		if (str[ft_strlen(str) - 1] == '\n')
			return (str);
	}
	return (str);
}
/*
int	main(void)
{
	int	fd;
	int	i;

	fd = open("test.txt", O_RDONLY);
	i = 0;
	if (fd == -1)
		printf("fd error\n");
	while (i < 139)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	return (0);
}*/
