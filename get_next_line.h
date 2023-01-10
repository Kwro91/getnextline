/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:44:54 by besalort          #+#    #+#             */
/*   Updated: 2023/01/10 15:06:39 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include	<unistd.h>
#include	<stddef.h>
#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<fcntl.h>

#ifndef	BUFFER_SIZE

#define	BUFFER_SIZE 64

#endif

char	*get_next_line(int fd);
char	*ft_read(char *stock, int fd, char *buf, int nb);
char	*ft_stock(char	*stock, int fd, char *buf, int len);
char	*ft_clear(char *stock, int n);
size_t	ft_strlen(const char *str);
#endif
