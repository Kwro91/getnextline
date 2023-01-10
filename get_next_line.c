/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:16:53 by besalort          #+#    #+#             */
/*   Updated: 2023/01/10 17:14:13 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h" 

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	static char	*stock = NULL;
	int		nb;
	
	nb = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	if (!stock)
	{	
		stock = malloc(1);
		stock[0] = '\0';
	}
	nb = read(fd, buf, BUFFER_SIZE);
	buf[nb] = '\0';
	printf("\nnb = %d\n", nb);
	printf("\n stock = %s\n", stock);
	if (nb == 0 || nb == -1)
		return (stock);
	else
		return (ft_read(stock, fd, buf, nb));
}

int main (void)
{
	int		fd;
	char *line;
		
	fd = open("./file", O_RDONLY);
	
	line = get_next_line(fd);
	printf("1ere %s\n", line);
	line = get_next_line(fd);
	printf("deuxieme %s\n", line);
	return (0);
}