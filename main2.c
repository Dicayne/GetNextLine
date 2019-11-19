/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:00:43 by vmoreau           #+#    #+#             */
/*   Updated: 2019/11/19 19:15:03 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int		stop(char *buf)
{
	int i;

	i = 0;
	if (buf != '\0')
	{
		while (buf[i] != '\0')
		{
			if (buf[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	dup = NULL;
	dup = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dup == NULL)
		return (NULL);
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_line(int fd)
{
	char *str;
	static char *temp;

	str = NULL;
	temp = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp != NULL)
	{
		str = ft_strdup(temp);
		while (stop(temp) == 0)
		{
			read(fd, temp, BUFFER_SIZE);
			temp[BUFFER_SIZE] = '\0';
			str = ft_strjoin(str, temp);
			if (str == NULL)
				break ;
		}
	}
	str = ft_strdup(str);
	return (str);
}

int		main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = get_line(fd);
	printf("%s\n", str);
	str = get_line(fd);
	printf("%s\n", str);
	str = get_line(fd);
	printf("%s\n", str);
	str = get_line(fd);
	printf("%s\n", str);
	str = get_line(fd);
	printf("%s\n", str);
	return (0);
}
