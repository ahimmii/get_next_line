/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:18:29 by ahimmi            #+#    #+#             */
/*   Updated: 2021/11/17 11:19:28 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	size_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (-1);
	return (i);
}

char	*line(char *reader_static)
{
	char	*output;
	int		size_n;

	if (!reader_static)
		return (NULL);
	size_n = size_line(reader_static);
	if (size_n == -1)
		return (ft_strdup(reader_static));
	output = (char *) malloc(((size_n) + 2) * sizeof(char));
	if (!output)
		return (NULL);
	ft_memmove(output, reader_static, size_n);
	output[size_n] = '\n';
	output[size_n + 1] = '\0';
	return (output);
}

char	*remove_d(char *reader_static)
{
	int	size_n;
	int	size_0;

	if (!reader_static)
		return (NULL);
	size_n = size_line(reader_static);
	size_0 = ft_strlen(reader_static);
	if (size_n == -1 || (size_n - size_0) == -1)
		return (free(reader_static), NULL);
	reader_static = ft_substr (reader_static, (size_n + 1),
			(size_0 - size_n - 1));
	return (reader_static);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*reader_static;
	int			reads;
	char		*output;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (size_line(reader_static) == -1)
	{
		reads = read(fd, str, BUFFER_SIZE);
		if (reads <= 0)
			break ;
		str[reads] = '\0';
		reader_static = ft_strjoin(reader_static, str);
	}
	free(str);
	output = line(reader_static);
	reader_static = remove_d(reader_static);
	return (output);
}
