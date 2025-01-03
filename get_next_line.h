/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreinoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:04:40 by dreinoso          #+#    #+#             */
/*   Updated: 2024/12/07 16:15:48 by dreinoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

char	*get_next_line(int fd);
char	*gnl_strdup(char *s);
size_t	gnl_strlen(char *s);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strjoin(char *s1, char *s2);
void	fill_str(char *res, char *s1, char *s2);
#endif
