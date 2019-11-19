/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:34:54 by vmoreau           #+#    #+#             */
/*   Updated: 2019/11/19 16:59:43 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

char	*buf_work(int fd)
{
	char *line;
	int ret;
	
	line = NULL;
	ret = read(fd, line, 1);
	return (line);
}

int		stop(char *buf)
{
	int i;

	i = 0;
	if (buf != NULL)
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

int		main(void)
{
	int fd;
	char *str;
	fd = open("test.txt", S_IRWXU);
	str = NULL;
	while (stop(str) == 0)
	{
		str = buf_work(fd);
		printf("%s", str);
	}
	return (0);
}
