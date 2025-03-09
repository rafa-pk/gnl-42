/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:36:42 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/09 13:27:09 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *str, char *buff)
{
	size_t		i;
	size_t		j;
	char		*merge;

	i = 0;
	j = 0;
	merge = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buff) + 1));
	if (!merge)
		return (free(merge), NULL);
	while (str && str[i] != '\0')
	{
		merge[i] = str[i];
		i++;
	}
	while (buff[j] && buff[j] != '\n')
	{
		merge[i + j] = buff[j];
		j++;
	}
	if (buff[j] == '\n')
		merge[i + j++] = '\n';
	merge[i + j] = '\0';
	return (free(str), merge);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\n' && str[i] != '\0' )
		i++;
	if (str && str[i] == '\n')
		i++;
	return (i);
}

char	*buff_cleaner(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
		i++;
	while (buff[i] != '\0')
	{
		buff[j] = buff[i];
		i++;
		j++;
	}
	while (j < BUFFER_SIZE)
		buff[j++] = '\0';
	return (buff);
}

