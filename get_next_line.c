/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:22:19 by vmoreau           #+#    #+#             */
/*   Updated: 2019/11/21 19:37:28 by vmoreau          ###   ########.fr       */
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

int		get_next_line(int fd, char **line)
{
	static char	*tmp;
	static int	ret;

	if (tmp != NULL)
	{
		if (stop_read(tmp) == 1)
		{
			(*line) = ft_cut_end(tmp);
			tmp = ft_take_end(tmp, ret);
			return (1);
		}
		(*line) = ft_cut_end(tmp);
	}
	ret = (tmp == NULL) ? 1 : ret;
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (tmp == NULL)
		return (-1);
	while (stop_read(tmp) == 0 && ret > 0)
	{
		ret = read(fd, tmp, BUFFER_SIZE);
		tmp[BUFFER_SIZE] = '\0';
		(*line) = ft_strjoin((*line), tmp);
	}
	(*line) = ft_cut_end((*line));
	tmp = ft_take_end(tmp, ret);
	return (ret);
}
