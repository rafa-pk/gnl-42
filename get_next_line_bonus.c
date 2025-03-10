/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:33:10 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/10 14:32:50 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	buff [FOPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	str = NULL;
	while (buff[fd][0] != '\0' || read(fd, buff[fd], BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buff[fd]);
		if (!str)
			return (NULL);
		buff_cleaner(buff[fd]);
		if (str[ft_strlen(str) - 1] == '\n')
			return (str);
	}
	return (str);
}

int	main(void)
{
	int	fd;
	int	fd2;
	int	fd3;
	int	i;

	fd = open("bonus1.txt", O_RDONLY);
	fd2 = open("bonus2.txt", O_RDONLY);
	fd3 = open("bonus3.txt", O_RDONLY);
	i = 0;
	while (i < 3)
	{
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd2));
		printf("%s\n", get_next_line(fd3));
		i++;
	}
	return (0);
}
