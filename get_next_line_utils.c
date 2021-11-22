/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:18:29 by ahimmi            #+#    #+#             */
/*   Updated: 2021/11/17 11:19:28 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	char		*dest;
	const char	*src;
	char		*dest1;
	const char	*src1;

	dest = destination;
	src = source;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		while (size--)
			*dest++ = *src++;
	}
	else
	{
		dest1 = destination + (size - 1);
		src1 = source + (size - 1);
		while (size--)
			(*dest1--) = (*src1--);
	}
	return (destination);
}

char	*ft_strjoin(const char *s1, char const *s2)
{
	int		i;
	char	*s;

	if (!s1 && !s2)
		return (0);
	i = 0;
	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (0);
	ft_memmove(s, s1, ft_strlen(s1));
	ft_memmove(s + ft_strlen(s1), s2, ft_strlen(s2));
	s[ft_strlen(s1)+ft_strlen(s2)] = '\0';
	free((char *)s1);
	return (s);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			x;
	char			*f;

	if (!s)
		return (0);
	i = start;
	if ((size_t)ft_strlen(s + i) < len)
		len = ft_strlen(s + i);
	f = (char *)malloc(sizeof(*s) * (len + 1));
	x = 0;
	if (!f)
		return (0);
	while (i < (unsigned int)ft_strlen(s) && x < len)
		f[x++] = s[i++];
	f[x] = '\0';
	free((char *)s);
	return (f);
}

char	*ft_strdup(const char *src)
{
	int		ln;
	int		i;
	char	*c;

	ln = ft_strlen(src);
	c = (char *)malloc(sizeof(*src) * (ln + 1));
	i = 0;
	if (!c)
		return (0);
	while (src[i] != '\0')
	{
		c[i] = src[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
