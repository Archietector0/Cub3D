/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:42:34 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/20 15:46:05 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*check_reminder(char **reminder, char **line)
{
	char *ptr_n;
	char *free_p;

	ptr_n = NULL;
	if (*reminder != NULL)
	{
		if ((ptr_n = ft_strchr1(*reminder, '\n')))
		{
			*ptr_n = '\0';
			ptr_n++;
			*line = ft_strdup1(*reminder);
			free_p = *reminder;
			*reminder = ft_strdup1(ptr_n);
			free(free_p);
		}
		else
		{
			*line = ft_strdup1(*reminder);
			free(*reminder);
			*reminder = NULL;
		}
	}
	else
		*line = ft_strdup1("");
	return (ptr_n);
}

int				return_error(char *buffer)
{
	free(buffer);
	return (-1);
}

int				return_value(char *buffer, char *ptr_n)
{
	free(buffer);
	if (ptr_n != NULL)
		return (1);
	else
		return (0);
}

int				get_next_line(int fd, char **line)
{
	char		*buffer;
	int			bwr;
	char		*ptr_n;
	static char	*reminder;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, buffer, 0) < 0) || !line
		|| !(buffer = malloc(BUFFER_SIZE * sizeof(char) + 1)))
		return (-1);
	ptr_n = check_reminder(&reminder, line);
	while (!ptr_n && (bwr = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		if (bwr == -1)
			return (return_error(buffer));
		buffer[bwr] = '\0';
		if ((ptr_n = ft_strchr1(buffer, '\n')) != 0)
		{
			*ptr_n = '\0';
			if ((reminder = ft_strdup1(++ptr_n)) < 0)
				return (return_error(buffer));
		}
		if ((*line = ft_strjoin1(*line, buffer)) < 0)
			return (return_error(buffer));
	}
	return (return_value(buffer, ptr_n));
}
