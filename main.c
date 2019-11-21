/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:00:43 by vmoreau           #+#    #+#             */
/*   Updated: 2019/11/21 18:53:42 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int		fd;
	char	*str;
	int		ret;
	int		round;
	ret = 1;
	fd = open("test.txt", O_RDONLY);
	round = 0;
	// ret = get_next_line(fd, &str);
	// printf(":%d:%s\n",round, str);
	// round++;
	// ret = get_next_line(fd, &str);
	// printf(":%d:%s\n",round, str);
	// round++;
	// ret = get_next_line(fd, &str);
	// printf(":%d:%s\n",round, str);
	// round++;
	// ret = get_next_line(fd, &str);
	// printf(":%d:%s\n",round, str);
	// round++;
	// ret = get_next_line(fd, &str);
	// printf(":%d:%s\n",round, str);
	// round++;
	// ret = get_next_line(fd, &str);
	// printf(":%d:%s\n",round, str);
	// ret = get_next_line(fd, &str);
	// printf("TiTA:%s\n\n%d\n", str, ret);
	while (ret > 0)
	{
		ret = get_next_line(fd, &str);
		printf("%d:%s\n",round, str);
		round++;
	}
	return (0);
}
