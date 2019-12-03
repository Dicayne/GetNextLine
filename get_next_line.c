/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:22:19 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/03 10:30:24 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		stop_read(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		return (1);
	else
		return (0);
}

void	ft_strwork(char **line, char tmp[BUFFER_SIZE + 1], int ret, char **stok)
{
	if (ret > 0)
	{
		(*line) = ft_cut_end((*stok));
		tmp = ft_take_end(tmp);
		free((*stok));
	}
	else
	{
		(*line) = ft_strdup((*stok));
		free((*stok));
	}
}

int		check_tmp(char **line, char tmp[BUFFER_SIZE + 1], char **stock)
{
	if (tmp != NULL)
	{
		if (stop_read(tmp) == 1)
		{
			(*line) = ft_cut_end(tmp);
			tmp = ft_take_end(tmp);
			return (1);
		}
		(*stock) = ft_strdup(tmp);
	}
	return (0);
}

void	ft_free(char **str, int mem)
{
	if ((stop_read((*str)) == 0 || mem == 1))
	{
		free((*str));
		(*str) = NULL;
	}
}

int		get_next_line(int fd, char **line)
{
	static char	tmp[BUFFER_SIZE + 1];
	char		*stock;
	int			ret;

	stock = NULL;
	ret = 1;
	if (check_tmp(line, tmp, &stock) == 1)
		return (1);
	while (stop_read(tmp) == 0 && ret > 0)
	{
		if ((ret = read(fd, tmp, BUFFER_SIZE)) == -1)
			break ;
		tmp[ret] = '\0';
		stock = ft_strjoin(stock, tmp);
	}
	ft_strwork(line, tmp, ret, &stock);
	if (fd == 0)
		return (1);
	return (ret >= 1 ? 1 : ret);
}
