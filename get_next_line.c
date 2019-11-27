/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:22:19 by vmoreau           #+#    #+#             */
/*   Updated: 2019/11/27 16:47:21 by victor           ###   ########.fr       */
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

void	ft_strwork(char **line, char **tmp, int ret, char **stock)
{
	if (ret > 0)
	{
		(*line) = ft_cut_end((*stock));
		(*tmp) = ft_take_end((*tmp), ret);
		free((*stock));
	}
	else
	{
		(*line) = ft_strdup((*stock));
		free((*tmp));
		free((*stock));
	}
}

int		check_tmp(char **line, char **tmp, int ret, char **stock)
{
	if ((*tmp) != NULL)
	{
		(*line) = ft_cut_end((*tmp));
		if (stop_read((*tmp)) == 1)
		{
			(*tmp) = ft_take_end((*tmp), ret);
			return (1);
		}
		(*stock) = ft_strdup((*line));
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		*stock;
	int			ret;

	stock = NULL;
	if (fd == -1)
		return (-1);
	ret = 1;
	if (check_tmp(line, &tmp, ret, &stock) == 1)
		return (1);
	while (stop_read(tmp) == 0 && ret > 0)
	{
		if(!(tmp = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		ret = read(fd, tmp, BUFFER_SIZE);
		printf("%d\n", ret);
		tmp[ret] = '\0';
		stock = ft_strjoin(stock, tmp);
	}
	ft_strwork(line, &tmp, ret, &stock);
	if (ret == -1)
		return (-1);
	if (fd == 0)
		return (1);
	return (ret >= 1 ? 1 : 0);
}
