/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:22:19 by vmoreau           #+#    #+#             */
/*   Updated: 2019/11/20 19:32:11 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		stop(char *buf)
{
	int i;

	i = 0;
	if (buf != NULL)
	{
		while (buf[i] != '\0')
		{
			if (buf[i] == '\n' || buf[i] == 0)
				return (1);
			i++;
		}
	}
	return (0);
}


char	*ft_strdup(char *s1)
{
	char	*dup;
	int		i;
	int		len;
	
	i = 0;
	len = 0;
	if (s1 == NULL)
		return (NULL);
	while(s1[len] != '\n' && s1[len] != '\0')
		len++;
	dup = NULL;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int		get_next_line(int fd, char **line)
{
	static char	*temp;
	static int	ret;
	static int	call;
	
	if (temp == NULL)
		temp = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp != NULL)
	{
		if (call == 0)
		{
			temp[0] = '\0';
			ret = read(fd, temp, BUFFER_SIZE);
		}
		(*line) = ft_strdup(temp);
		while (stop(temp) == 0 && ret > 0)
		{
			if (call > 0)
				ret = read(fd, temp, BUFFER_SIZE);
			temp[BUFFER_SIZE] = '\0';
			(*line) = ft_strjoin((*line), temp);
			if ((*line) == NULL)
				break ;
		}
	}
	temp = ft_take_end(temp);
	(*line) = ft_strdup((*line));
	call++;
	return (ret);
}
