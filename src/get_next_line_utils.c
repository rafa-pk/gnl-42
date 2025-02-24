/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:36:42 by raica-ba          #+#    #+#             */
/*   Updated: 2025/02/24 12:46:07 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	size_t		buff_size;
	char		*merge;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	buff_size = ft_strlen(s1) + ft_strlen(s2);
	merge = (char *)malloc(sizeof(char) * (buff_size + 1));
	if (!merge)
		return (NULL);
	while (s1[i] != '\0')
	{
		merge[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		merge[i + j] = s2[j];
		j++;
	}
	merge[i + j] = '\0';
	return (merge);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	buffer_cleaner(char	*buffer)
{

}

