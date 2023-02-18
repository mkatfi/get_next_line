/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:00:43 by mkatfi            #+#    #+#             */
/*   Updated: 2022/11/26 12:57:02 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_line(char *s)
{
	int		i;
	char	*p;

	i = 0;
	if (!s || s[i] == '\0')
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	p = malloc(sizeof(char) * (i + 2));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		p[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		p[i++] = '\n';
	p[i] = '\0';
	return (p);
}

char	*ft_cha(char *s)
{
	int		i;
	int		j;
	char	*k;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (!s || s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	k = malloc (sizeof(char) * (ft_strlen(s) - i + 1));
	if (!k)
	{
		free(s);
		return (NULL);
	}
	i++;
	j = 0;
	while (s[i])
		k[j++] = s[i++];
	k[j] = '\0';
	free(s);
	return (k);
}

char	*ft_read(int fd, char *container)
{
	char	*buff;
	int		i;

	i = 1;
	buff = ft_calloc(BUFFER_SIZE + 1 * sizeof(char), 1);
	if (!buff)
		return (NULL);
	while (ft_strchr(buff) == 0 && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			free(container);
			return (NULL);
		}
		buff[i] = '\0';
		container = ft_strjoin(container, buff);
	}
	free(buff);
	return (container);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s[fd] = ft_read(fd, s[fd]);
	line = ft_line(s[fd]);
	s[fd] = ft_cha(s[fd]);
	return (line);
}
