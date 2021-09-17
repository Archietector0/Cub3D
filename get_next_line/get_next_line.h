/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarth <tbarth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:42:51 by tbarth            #+#    #+#             */
/*   Updated: 2021/03/20 15:44:59 by tbarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int		get_next_line(int fd, char **line);
size_t	ft_strlen1(const char *s);
char	*ft_strdup1(const char *s1);
char	*ft_strchr1(const	char *s, int c);
char	*ft_strjoin1(char *s1, char *s2);

#endif
