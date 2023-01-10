/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:45:17 by besalort          #+#    #+#             */
/*   Updated: 2023/01/10 17:19:41 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_clear(char *stock, int n)
{
	int		i;

	i = 0;
	n++;
	while (stock[n] && stock[n] != '\n' && stock[n] != EOF)
	
	{
		stock[i] = stock[n];
		i++;
		n++;
	}
	stock[i] = '\0';
	return (stock);
}

char	*ft_big(char	*stock, int len)
{
	char	*tab;
	int		j;

	j = 0;
	tab = malloc (len + 1);// si c'est pas le cas on augmente la taille de stock pour pouvoir rappeler read et continuer la ligne dans le cas ou le BUFFER_SIZE < taille ligne
	if (!tab)
		return (NULL);
	while (j < len)
	{
		tab[j] = stock[j];
		j++;
	}
	tab[j] = '\0';
	stock = malloc(len + BUFFER_SIZE);
	if (!stock)
		return (NULL);
	j = 0;
	while (j < len)
	{
		stock[j] = tab[j];
		j++;
	}
	return (stock);
}

char	*ft_read(char *stock, int fd, char *buf, int len)
{
	int		i;
	int		j;
	char	*tab;

	ft_strlen(stock);
	if (i == 0)//on verifie que stock est pas vide, si c'est le cas on le malloc de la taille du buf
		stock = malloc(len + 1);
	if (!stock)
		return (NULL);
	j = 0;
	while (buf[j])//on remplis stock avec buf
	{
		stock[i + j] = buf[j];
		j++;
	}
	stock[i + j] = '\0';
	i = 0;
	j = 0;
	while (stock[i]) 
	{
		if (stock[i] == '\n') // si stock est un saut a la ligne on malloc tab on copie stock avant le \n dans tab, on clear stock avant le \n et on return tab
		{
			tab = malloc(i);
			if (!tab)
				return (NULL);
			while (j < i)
			{
				tab[j] = stock[j];
				j++;
			}
			tab[j] = '\0';
			ft_clear(stock, i);
			printf("\n apres le clear, stock = %s\n", stock);
			return (tab);
		}
		i++;
	}
	stock = ft_big(stock, len);
	get_next_line(fd);
	return (stock);
}
