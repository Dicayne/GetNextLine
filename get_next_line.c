/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:22:19 by vmoreau           #+#    #+#             */
/*   Updated: 2019/11/22 18:08:39 by vmoreau          ###   ########.fr       */
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
		(*line) = ft_cut_end(tmp);
		if (stop_read(tmp) == 1)
		{
			tmp = ft_take_end(tmp, ret);
			return (1);
		}
	}
	ret = (tmp == NULL) ? 1 : ret;
	while (stop_read(tmp) == 0 && ret > 0)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		ret = read(fd, tmp, BUFFER_SIZE);
		tmp[BUFFER_SIZE] = '\0';
		(*line) = ft_strjoin((*line), tmp);
	}
	(*line) = ft_cut_end((*line));
	tmp = ft_take_end(tmp, ret);
	ret = (fd == 0 ? 1 : ret);
	return (ret >= 1 ? 1 : 0);
}
