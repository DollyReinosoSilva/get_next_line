/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreinoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:37:38 by dreinoso          #+#    #+#             */
/*   Updated: 2024/12/12 12:37:46 by dreinoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*_fill_line_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		if (!left_c)
			left_c = gnl_strdup("");
		tmp = left_c;
		left_c = gnl_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (gnl_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

char	*_set_line(char *line_buffer)
{
	char	*left_c;
	ssize_t	i;

	i = 0;
	if (!line_buffer)
		return (NULL);
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[i + 1] == 0)
		return (NULL);
	left_c = gnl_substr(line_buffer, i + 1, gnl_strlen(line_buffer) - i);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	line_buffer[i + 1] = 0;
	return (left_c);
}

char	*get_next_line(int fd)
{
	static char	*left_c[1024];
	char		*line;
	char		*buffer;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	line = NULL;
	buffer = NULL;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = _fill_line_buffer(fd, left_c[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_c[fd] = _set_line(line);
	return (line);
}
