/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:11:28 by bede-car          #+#    #+#             */
/*   Updated: 2022/07/20 21:09:01 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (s == NULL)
		return (s);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_backup(char *hold, char *line)
{
	char	*backup;
	int		cut;

	cut = ft_strlen(line);
	backup = ft_substr(hold, cut, (ft_strlen(hold)-cut));
	free(hold);
	if (!*backup)
	{
		free(backup);
		backup = NULL;
	}
	return (backup);
}

char	*ft_find_line(char *hold)
{
	char	*line;
	int		i;

	i = 0;
	while (hold[i] != '\n' && hold[i])
		i++;
	if (hold[i] == '\0')
		i++;
	line = ft_substr(hold, 0, i + 1);
	return (line);
}

char	*ft_read(int fd, char *hold)
{
	int		result_read;
	char	*reading;
	char	*temp;

	if (hold == NULL)
		hold = ft_strdup("");
	reading = malloc (BUFFER_SIZE + 1);
	result_read = 1;
	while (!ft_strchr(hold, '\n') && result_read > 0)
	{
		result_read = read(fd, reading, BUFFER_SIZE);
		if (result_read <= 0 && hold[0] == '\0')
			return (free(reading), hold);
		reading[result_read] = '\0';
		temp = hold;
		hold = ft_strjoin(temp, reading);
		free(temp);
		temp = NULL;
	}
	free(reading);
	return (hold);
}

char	*get_next_line(int fd)
{
	static char	*hold = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD_SIZE)
		return (NULL);
	hold = ft_read(fd, hold);
	if (!*hold)
	{
		free(hold);
		hold = NULL;
		return (NULL);
	}
	line = ft_find_line(hold);
	if (*line == '\0')
		return (NULL);
	hold = ft_backup(hold, line);
	return (line);
}
