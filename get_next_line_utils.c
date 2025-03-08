/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:36:42 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/08 14:50:48 by raica-ba         ###   ########.fr       */
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

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	byte_value;
	unsigned char	*string;

	i = 0;
	byte_value = (unsigned char) c;
	string = (unsigned char *) b;
	while (i < len)
	{
		string[i] = byte_value;
		i++;
	}
	return (b);
}
